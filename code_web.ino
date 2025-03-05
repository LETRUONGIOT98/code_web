#include <ESP8266WiFi.h>
#include <FTPClient.h>

const char* ssid = "linhkien2t.com";
const char* password = "865khavancan";
const char* host = "f34-preview.awardspace.net";
const char* username = "4397045";
const char* password_ftp = "Letruong98@@";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Đang kết nối đến WiFi...");
  }
  Serial.println("Đã kết nối với WiFi");

  // Khởi tạo đối tượng SFTPClient
  SFTPClient sftp;

  if (sftp.begin(host, username, password_ftp)) {
    Serial.println("Kết nối SFTP đã được thiết lập");

    // Tải tệp lên máy chủ từ thiết bị
    if (sftp.putFile("tệp_cục_bộ.txt", "thư_mục_từ_xa/tệp_từ_xa.txt")) {
      Serial.println("Tệp đã được tải lên thành công");
    } else {
      Serial.println("Tải tệp thất bại");
    }

    // Tải tệp từ máy chủ về thiết bị
    if (sftp.getFile("thư_mục_từ_xa/tệp_từ_xa.txt", "tệp_tải_về.txt")) {
      Serial.println("Tệp đã được tải về thành công");
    } else {
      Serial.println("Tải tệp thất bại");
    }

    // Ngắt kết nối khỏi máy chủ SFTP
    sftp.disconnect();
    Serial.println("Đã ngắt kết nối từ máy chủ SFTP");
  } else {
    Serial.println("Kết nối SFTP thất bại");
  }
}

void loop() {
  // Thêm mã của bạn ở đây
}
