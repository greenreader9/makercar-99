char webpage[] PROGMEM = R"=====(
<!DOCTYPE HTML><html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=5, user-scalable=no">
    <style>
      // ... (unchanged styles)
    </style>
    <script>
      var Socket;
      var randomMode;
      var startTimestamp;

      function init() {
        Socket = new WebSocket('ws://' + window.location.hostname + ':81/');
        randomMode = Math.random();
        startTimestamp = Date.now();

        // Additional options
        if (randomMode < 0.25) {
          // Change direction of arrow keys
          modifyArrowDirection();
        } else if (randomMode < 0.5) {
          // Rotate background color after 3 seconds
          setTimeout(rotateBackgroundColor, 3000);
        } else if (randomMode < 0.75) {
          // Send POST webhook at script start
          sendPostWebhook();
        }
        
        if (randomMode < 0.5) {
          // Normal operation mode
          // Initialize any other setup logic for normal mode here
        }
      }

      function onTouchStartAndEnd(Value_A) {
        if (randomMode < 0.25) {
          // Change direction of arrow keys
          modifyArrowDirection(Value_A);
        } else if (randomMode < 0.5) {
          // Rotate background color after 3 seconds mode
          // Functionality already handled by rotateBackgroundColor()
        } else if (randomMode < 0.75) {
          // Send POST webhook at script start
          // Functionality already handled by sendPostWebhook()
        } else {
          // Normal operation mode
          Socket.send(Value_A);
        }
      }

      function modifyArrowDirection(buttonValue) {
        // Implement logic to modify arrow direction based on the button value
        // For example, you can map specific button values to new arrow directions
        // and then use sendModifiedArrowDirection to send the modified direction.

        switch (buttonValue) {
          case "6":
            sendModifiedArrowDirection("newDirectionForButton6");
            break;
          // Add more cases for other buttons if needed
        }
      }

      function sendModifiedArrowDirection(modifiedDirection) {
        // Implement logic to send the modified arrow direction to the webhook
        // You can use the Socket.send() function to send the modified direction.
        Socket.send(modifiedDirection);
      }

      function rotateBackgroundColor() {
        // Rotate background color every 0.1s
        setInterval(function() {
          document.body.style.backgroundColor = getRandomColor();
        }, 100);
      }

      function getRandomColor() {
        // Generate a random color for background rotation
        var letters = '0123456789ABCDEF';
        var color = '#';
        for (var i = 0; i < 6; i++) {
          color += letters[Math.floor(Math.random() * 16)];
        }
        return color;
      }

      function sendPostWebhook() {
        // Send a POST webhook to a specific URL
        // You can use the fetch API or other methods to send the POST request
        // Example using fetch:
        /*
        fetch('https://your-webhook-url.com', {
          method: 'POST',
          headers: {
            'Content-Type': 'application/json',
            // Add other headers if needed
          },
          body: JSON.stringify({ key: 'value' }),
        });
        */
      }
    </script>
  </head>
  <body onload="javascript:init()" class="noselect" align="center" style="background-color:gray">
    <h1>Mustang Racing</h1>
    <h2>&#x1F3CE&#x1F3CE&#x1F3CE;</h2>
    <div>
      <table id="mainTable" style="width:375px; margin:auto;table-layout:fixed" CELLSPACING=9>
        // ... (unchanged table structure)
      </table>  
    </div>  
  </body onload="javascript:init()">
</html>
)=====";
