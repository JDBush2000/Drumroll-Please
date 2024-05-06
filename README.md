# Drumroll-Please
Additional files needed for assembly of the custom syringe controller compatible with the game "Drumroll, Please"

Required Components:
  - 6x6x8mm or 6x6x9.5mm tactile buttons
  	- Included in this set of tactile buttons: https://www.amazon.com/dp/B0858XRGYW?psc=1&ref=ppx_yo2ov_dt_b_product_details
  - A LP103454 Lipo Battery. Original controller was tested and created with a battery of 3.7V and 2000mAh.
  	- Known working battery can be found here: https://www.amazon.com/dp/B0858XRGYW?psc=1&ref=ppx_yo2ov_dt_b_product_details
  - The XIAO ESP32C3 microcontroller by Seeed Studio
  	- Can be found here: https://www.seeedstudio.com/Seeed-XIAO-ESP32C3-p-5431.html
  - Requires jumper cables and header pins for interfacing between the button, XIAO, and battery
  - Will require basic soldering skills to assemble

Required Code:
  - Begin by going to this link and following Seeed Studio's official Getting Started guide for the XIAO ESP32C3 board. Importantly, follow the instructions under the "Software Setup" header to download the Arduino IDE and necessary packages.
 - Once the Arduino IDE is set up, connect your XIAO board to a PC via a USB-C cable and ensure that the IDE detects the board.
- Download the file "Syringe_Controller.ino" from this repository and open it in the Arduino IDE.
	-  If you have already connected the button to the D0 contact, you can open the serial monitor with the XIAO connected to the IDE to see the current sleep timer. If you press the button, the console should print "Button Pressed" and the timer should restart.


Required 3D Model Files:
  - COMING SOON

Required Assembly:
  - Once all parts are 3D printed, it is important to assemble each part in a specific order:
  	- In the "body" of the syringe, drop the "needle" part (the one with the spring attached) and position the cylindrical part through the hole at the tip of the syringe.
	 - Next, identify the two parts shaped like discs. You should have one thicker disc and another thin one.
	 - Place your button facing upwards on top of the thinner disc with the legs poking through the other end.
	 - Place the thicker disc over the top of the button.
	 			 Note: You will likely need to adhere the button to the thin disc as well as the thicker disc to the thinner disc using a substance such as hot glue or super glue made for plastics
	- Once each disc is stuck together and the button is sturdy, progress to the next steps to connect the electronics.
  - You will need to connect two of the legs of the button (connect only the legs on the *same* side) to the D0 and GND contacts on the XIAO board with your header pins and jumper wires. You will need approximately at least 4 Inches of wire length between the contacts and the button.
  - Connect the antenna that comes with the XIAO ESP32C3 to the connector on the end of the board opposite the USB-C connector
  - Connect the positive and negative terminals of your battery to the '+' and '-' contacts designated with the "BAT" label on the back of the XIAO board.
  	- CAUTION: Please be careful not to short-circuit the terminals of your battery during assembly as this may damage the components.
  - Once all components are connected and functioning, continue with the 3D part assembly:
  	- Slide the discs with the button into the syringe body. Make sure that the button is facing towards the needle of the syringe so that the plastic piece will make contact with the button when pressed down.
  	- Identify the "bracket" piece of the syringe. Place the bracket into the body on top of the discs with the button.
   		- Take care to not pinch any wires inside the body.
     	- If you have already connected the button to the XIAO board, it is recommended to route the battery and XIAO through the bracket outside of the syringe before sliding the bracket into place.
  	- Finally, place the battery against the inner wall of the syringe body and bracket. Place the XIAO higher up inside the body so that the Bluetooth antenna is near the open end of the syringe.
  	- Begin to slide the end cap into the open end of the syringe body.
   		- Again, take care not to pinch any wires inside the body.
     	- As with the disc pieces, it is recommended to secure the end cap into the body using an adhesive such as super glue around the edges of the cap.
      	- Note that this will be sealing all components inside the controller. Be sure to test the functionality thoroughly before committing to final assembly.

Usage:
  - When powered on for the first time, the board will go into pairing mode.
  - At this stage, you should be able to identify it with any Bluetooth capable device under the name "Syringe Controller"
  - After 28000000 clock cycles (a little over 15 minutes in real time), the device will enter sleep mode. At this stage, pressing the button connected to the D0 pin will wake up the device.
  - Once paired to a device, pressing the button connected to the D0 pin will enter a "middle mouse click" input on whatever device it is connected to.
  - This allows the controller to activate a middle mouse click while playing the game "Drumroll, Please", thus activating the injection boost within said game.
