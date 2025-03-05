const char* htmlContent PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="refresh" content="5" />
    <style>
        /* CSS for the interface */
       body {
            font-family: Arial, sans-serif;
            text-align: center;
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;
            height: 50vh;
            background-color: #00000;
            width: auto;
            height: auto;
            position: absolute;
            left: 50%;
            top: 50%;
            transform: translate(-50%, -50%);
        }

        .grid-container {
            display: flex;
            grid-template-columns: repeat(6, 1fr); /* 6 columns */
            grid-gap: 10px; /* Reduce gap between elements */
            justify-items: center;
            align-items: center;
        }

        .data-container {
            display: flex;
            flex-direction: row;
            align-items: center;
        }
        .data-box {
            width: 150px; /* Set a fixed width for all data-box elements */
            height: 150px; /* Reduce the height */
            text-align: center;
        }

        .button-container {
            display: flex;
            flex-direction: column;
            align-items: center;
        }

        .button {
            width: 100px; /* Reduce the width */
            padding: 10px 15px; /* Adjust padding */
            font-size: 14px; /* Reduce font size */
            cursor: pointer;
            margin: 5px;
        }
    </style>

    <!-- To use the JustGage library -->
    <script src="https://cdnjs.cloudflare.com/ajax/libs/raphael/2.1.4/raphael-min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/justgage/1.2.9/justgage.min.js"></script>
</head>
<body>
    <h1>?i?u khi?n v� gi�m s�t nh� y?n th�ng minh Linhkien2t.com</h1>

   <div class="grid-container">
        <!-- Row 1 -->
        <div class="data-container">
            <div class="data-box" id="dataBox5">Nhi?t ?? hi?n t?i</div>
            <div class="button-container">
                <button class="button" onclick="executeAction('http://165.154.229.38:8080/sBZOt7CZoUC1oIh-EvQ6yZzbZi5nX8dC/update/V7?value=1')">B?t thi?t b? 1</button>
                <button class="button" onclick="executeAction('http://165.154.229.38:8080/sBZOt7CZoUC1oIh-EvQ6yZzbZi5nX8dC/update/V7?value=0')">T?t thi?t b? 1</button>
            </div>
        </div>
            </div>
        <div class="data-container">
            <div class="data-box" id="dataBox6">?? ?m hi?n t?i</div>
            <div class="button-container">
                <button class="button" onclick="executeAction('http://165.154.229.38:8080/sBZOt7CZoUC1oIh-EvQ6yZzbZi5nX8dC/update/V8?value=1')">B?t thi?t b? 2</button>
                <button class="button" onclick="executeAction('http://165.154.229.38:8080/sBZOt7CZoUC1oIh-EvQ6yZzbZi5nX8dC/update/V8?value=0')">T?t thi?t b? 2</button>
            </div>
        </div>
    

    <div class="grid-container">
        <!-- Row 2 -->
        <div class="data-container">
            <div class="data-box" id="dataBox1">Set nhi?t ?? th?p
            <div class="button-container">
                <button class="button" onclick="executeAction('http://165.154.229.38:8080/sBZOt7CZoUC1oIh-EvQ6yZzbZi5nX8dC/update/V9?value=1')">T?ng</button>
                <button class="button" onclick="executeAction('http://165.154.229.38:8080/sBZOt7CZoUC1oIh-EvQ6yZzbZi5nX8dC/update/V10?value=1')">Gi?m</button>
            </div>
        </div></div>

        <div class="data-container">
            <div class="data-box" id="dataBox2">Set nhi?t ?? cao
            <div class="button-container">
                <button class="button" onclick="executeAction('http://165.154.229.38:8080/sBZOt7CZoUC1oIh-EvQ6yZzbZi5nX8dC/update/V11?value=1')">T?ng</button>
                <button class="button" onclick="executeAction('http://165.154.229.38:8080/sBZOt7CZoUC1oIh-EvQ6yZzbZi5nX8dC/update/V12?value=1')">Gi?m</button>
            </div>
        </div>
        </div>
        <div class="data-container">
            <div class="data-box" id="dataBox3">Set ?? ?m th?p
            <div class="button-container">
                <button class="button" onclick="executeAction('http://165.154.229.38:8080/sBZOt7CZoUC1oIh-EvQ6yZzbZi5nX8dC/update/V13?value=1')">T?ng</button>
                <button class="button" onclick="executeAction('http://165.154.229.38:8080/sBZOt7CZoUC1oIh-EvQ6yZzbZi5nX8dC/update/V14?value=1')">Gi?m</button>
            </div></div>
    

        <div class="data-container">
            <div class="data-box" id="dataBox4">Set ?? ?m cao 
            <div class="button-container">
                <button class="button" onclick="executeAction('http://165.154.229.38:8080/sBZOt7CZoUC1oIh-EvQ6yZzbZi5nX8dC/update/V15?value=1')">T?ng</button>
                <button class="button" onclick="executeAction('http://165.154.229.38:8080/sBZOt7CZoUC1oIh-EvQ6yZzbZi5nX8dC/update/V16?value=1')">Gi?m</button>
            </div></div>
        </div>
    </div>

    <script>
        // Function to execute actions silently without changing the UI
        function executeAction(url) {
            fetch(url)
                .then(response => {
                    // Do nothing on success
                })
                .catch(error => {
                    console.error(`Error executing action: ${error}`);
                });
        }

        // Function to update Data using JustGage
        function updateDataGauge(dataBoxId, url, title, label) {
            // Create a JustGage instance for the specified Data
            const dataGauge = new JustGage({
                id: dataBoxId, // ID of the element to display the gauge
                value: 0, // Initial value (you can set it to Loading... initially)

                min: 0,
                max: 100,
                title: title,
                label: label,
                width: 150, // Set the width for the gauge
            });

            // Function to fetch data and update the gauge
            function fetchDataAndUpdateGauge() {
                fetch(url)
                    .then(response => response.text())
                    .then(data => {
                        // Parse the data as a number and update the gauge
                        const numericData = parseFloat(data.match(/\d+/)[0]);
                        dataGauge.refresh(numericData);
                    })
                    .catch(error => {
                        console.error(`Error fetching data for ${dataBoxId}: ${error}`);
                    });
            }

            // Call the function to update the gauge
            fetchDataAndUpdateGauge();
        }

        // Call the function for each Data box
        updateDataGauge('dataBox1', 'http://165.154.229.38:8080/sBZOt7CZoUC1oIh-EvQ6yZzbZi5nX8dC/get/V0', 'Title 1', '�C');
        updateDataGauge('dataBox2', 'http://165.154.229.38:8080/sBZOt7CZoUC1oIh-EvQ6yZzbZi5nX8dC/get/V1', 'Title 2', '�C');
        updateDataGauge('dataBox3', 'http://165.154.229.38:8080/sBZOt7CZoUC1oIh-EvQ6yZzbZi5nX8dC/get/V2', 'Title 3', '%');
        updateDataGauge('dataBox4', 'http://165.154.229.38:8080/sBZOt7CZoUC1oIh-EvQ6yZzbZi5nX8dC/get/V3', 'Title 4', '%');
        updateDataGauge('dataBox5', 'http://165.154.229.38:8080/sBZOt7CZoUC1oIh-EvQ6yZzbZi5nX8dC/get/V4', 'Title 5', '�C');
        updateDataGauge('dataBox6', 'http://165.154.229.38:8080/sBZOt7CZoUC1oIh-EvQ6yZzbZi5nX8dC/get/V5', 'Title 6', '%');
    </script>
</body>
</html>
)=====";
