package mystudentlistDB.dao;

import mystudentlistDB.Studente;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

public class StudentDAOPostgres implements StudentDAO {
    private final String URL = "jdbc:postgresql://localhost:5432/studenti";
    private final String USER = "emanueletocci";
    private final String PASSWORD = "mypassword";


    @Override
    public void inserisci(Studente s) throws Exception {
        try (Connection connection = DriverManager.getConnection(URL, USER, PASSWORD);
             Statement statement = connection.createStatement()
        ) {
            String insert = "INSERT INTO studentdb.student(nome, cognome, matricola) VALUES (%s, %s, %s);";
            statement.executeUpdate(insert);
        }
    }

    @Override
    public void rimuovi(Studente s) throws Exception {
        try (Connection connection = DriverManager.getConnection(URL, USER, PASSWORD);
             Statement statement = connection.createStatement()
        ) {
            String delete = String.format("DELETE FROM studentdb.student WHERE matricola = '%s';", s.getMatricola());
            statement.executeUpdate(delete);
        }
    }

    @Override
    public void aggiorna(Studente s) throws Exception {
        try (Connection connection = DriverManager.getConnection(URL, USER, PASSWORD);
             Statement statement = connection.createStatement()
        ) {
            String update = String.format("UPDATE studentdb.student SET nome='%s', cognome='%s', WHERE matricola='%s;", s.getNome(), s.getCognome(), s.getMatricola());
            statement.executeUpdate(update);
        }
    }

    @Override
    public Studente cerca(String matricola) throws Exception {
        Studente s = null;
        try (Connection connection = DriverManager.getConnection(URL, USER, PASSWORD);
             Statement statement = connection.createStatement()
        ) {
            String update = String.format("SELECT * FROM studentdb.student WHERE matricola = '%s';", matricola);
            ResultSet resultSet = statement.executeQuery(update);
            if (resultSet.next()) {
            String nome = resultSet.getString("nome");
            String cognome = resultSet.getString("cognome");
            s = new Studente(nome, cognome, matricola);
            }
        }
        return s;
    }

    @Override
    public List<Studente> elencaTutti() throws Exception {
        List<Studente> listaStudenti = new ArrayList<>();

        try (Connection connection = DriverManager.getConnection(URL, USER, PASSWORD);
             Statement statement = connection.createStatement()
        ) {
            String update = String.format("SELECT * FROM studentdb.student");
            ResultSet resultSet = statement.executeQuery(update);

            while(resultSet.next()) {
                elencaTutti().add(new Studente(resultSet.getString("nome"), resultSet.getString("cognome"), resultSet.getString("matricola")));
            }
        }
        return listaStudenti;
    }
}
