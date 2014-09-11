XBee and Spark Core - Remote Door Monitor using XBee Digital Input
------------------------------------------------------------------

This is the part 2 of my XBee and Spark Core series. In this part I worked on a simple remote door monitor using XBee, Spark Core and a Magnetic Contact Switch (Door Sensor). 

In this project, the remote XBee is configured as Router AT. The DIO4 of the XBee is setup for Digital Input (3) and it is also configured to send IO Sample data every 1 second (setting IR to 3E8 hex). The Magnetic Contact Switch is connected to DIO4 of this XBee, so when the door is closed the DIO4 will be HIGH and when the door is open the DIO4 will be LOW.

A Coordinator XBee is connected to Spark Core using Serial. The Coordinator receives the IO Sample data that Remote XBee is sending and parse it to see whether DIO4 is HIGH/LOW. An event is generated based on the door state.

The companion web page listens for the above event and display some graphics based on the whether the door is open or closed.

I am using XBee Library ported by @peekay123. The Spark Core continuously reads XBee packets and look for packets with API ID ZB_IO_SAMPLE_RESPONSE. This is the API ID of the IO Sample Data. If it is IO Sample data, then read the data into ZBRxIoSampleResponse class. The ZBRxIoSampleResponse.isDigitalOn() method can be used to find whether a particular PIN is ON/OFF.

**Screehshots**

![Spark Core and Coordinator XBee](https://raw.githubusercontent.com/krvarma/Spark_XBee_Remote_Door_Monitor/master/images/IMG_0158.JPG)

![Remote XBee and Door Sensor](https://raw.githubusercontent.com/krvarma/Spark_XBee_Remote_Door_Monitor/master/images/IMG_0154.JPG)

![Web Page](https://raw.githubusercontent.com/krvarma/Spark_XBee_Remote_Door_Monitor/master/images/webpage.png)


**Demo Video**