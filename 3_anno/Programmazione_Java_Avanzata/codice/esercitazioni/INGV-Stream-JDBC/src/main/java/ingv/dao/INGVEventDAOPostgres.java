package ingv.dao;

import ingv.INGVEvent;

import java.sql.*;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

public class INGVEventDAOPostgres implements INGVEventDAO{
    private final String URL = "jdbc:postgresql://localhost:5433/ingv";
    private final String USER = "postgres";
    private final String PASSWORD = "Mypass";

    /*
     * 1. Caricare Driver
     * 2. Aprire connessione
     * 3. Creare statement
     * 4. Eseguire query
     * 5. Chiudere connessione
     */

    @Override
    public List<INGVEvent> getAllEvents() throws Exception {
        List<INGVEvent> events = new ArrayList<>();
        try(Connection connection = DriverManager.getConnection(URL, USER, PASSWORD);
            PreparedStatement stmt = connection.prepareStatement("SELECT * FROM public.events");
        ){
            stmt.executeQuery();
            ResultSet results = stmt.getResultSet();
            while(results.next()){
                events.add(new INGVEvent(results.getString("eventID"), results.getObject("time", LocalDateTime.class), results.getDouble("magnitude"), results.getString("location")));
            }
            return events;
        }
    }

    @Override
    public void saveEvent(INGVEvent event) throws Exception{
        try (Connection connection = DriverManager.getConnection(URL, USER, PASSWORD);
             PreparedStatement stmt = connection.prepareStatement(
                     "INSERT INTO public.events(\"eventID\", time, magnitude, location) VALUES (?, ?, ?, ?) " +
                             "ON CONFLICT (\"eventID\") DO NOTHING"
             );
        ) {
            stmt.setString(1, event.getEventID());
            stmt.setObject(2, event.getTime());
            stmt.setDouble(3, event.getMagnitude());
            stmt.setString(4, event.getEventLocationName());
            stmt.executeUpdate();
        }

    }

    @Override
    public void deleteEvent(INGVEvent event) throws Exception {
        try (Connection connection = DriverManager.getConnection(URL, USER, PASSWORD);
             PreparedStatement stmt = connection.prepareStatement("DELETE FROM public.events WHERE eventID = ?");
        ) {
            stmt.setString(1, event.getEventID());
            stmt.executeUpdate();
        }
    }

    @Override
    public void updateEvent(INGVEvent event) throws Exception{
        try (Connection connection = DriverManager.getConnection(URL, USER, PASSWORD);
             PreparedStatement stmt = connection.prepareStatement("UPDATE public.events SET time = ?, magnitude = ?, location = ? WHERE eventID = ?");
        ) {
            stmt.setObject(1, event.getTime());
            stmt.setDouble(2, event.getMagnitude());
            stmt.setString(3, event.getEventLocationName());
            stmt.setString(4, event.getEventID());
            stmt.executeUpdate();
        }
    }

    @Override
    public INGVEvent getEventByID(String eventID) throws Exception{
        try (Connection connection = DriverManager.getConnection(URL, USER, PASSWORD);
             PreparedStatement stmt = connection.prepareStatement("SELECT * FROM public.events WHERE eventID = ?");
        ) {
            stmt.setString(4, eventID);
            ResultSet results = stmt.executeQuery();
            if(results.next()){
                String id = results.getString("eventID");
                LocalDateTime time = results.getObject("time", LocalDateTime.class);    // specifico il tipo di oggetto passando la classe
                double magnitude = results.getDouble("magnitude");
                String location = results.getString("location");
                return new INGVEvent(id, time, magnitude, location);
            } else {
                return null;
            }

        }
    }
}
