package ingv.dao;

import ingv.INGVEvent;
import java.util.List;

public interface INGVEventDAO {
    List<INGVEvent> getAllEvents() throws Exception;
    void saveEvent(INGVEvent event) throws Exception;
    void deleteEvent(INGVEvent event) throws Exception;
    void updateEvent(INGVEvent event) throws Exception;
    INGVEvent getEventByID(String eventID) throws Exception;
}
