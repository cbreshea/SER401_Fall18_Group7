-- MySQL dump 10.13  Distrib 8.0.15, for macos10.14 (x86_64)
--
-- Host: localhost    Database: arduinolibraries
-- ------------------------------------------------------
-- Server version	8.0.15

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
 SET NAMES utf8 ;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Neopixel`
--

DROP TABLE IF EXISTS `Neopixel`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `Neopixel` (
  `productID` int(11) DEFAULT NULL,
  `stripName` varchar(255) DEFAULT NULL,
  `AnalogPins` int(11) DEFAULT NULL,
  `DigitalPins` int(11) DEFAULT NULL,
  `preSetPins` int(11) DEFAULT NULL,
  `length` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Neopixel`
--

LOCK TABLES `Neopixel` WRITE;
/*!40000 ALTER TABLE `Neopixel` DISABLE KEYS */;
INSERT INTO `Neopixel` VALUES (1376,'Digital RGB LED Strip - White 30 LED - WHITE',0,1,1,NULL),(1138,'Adafruit NeoPixel Digital RGB LED Strip - White 60 LED - WHITE',0,1,1,1),(1138,'Adafruit NeoPixel Digital RGB LED Strip - White 60 LED - WHITE',0,1,1,2),(1138,'Adafruit NeoPixel Digital RGB LED Strip - White 60 LED - WHITE',0,1,1,3),(1138,'Adafruit NeoPixel Digital RGB LED Strip - White 60 LED - WHITE',0,2,2,4);
/*!40000 ALTER TABLE `Neopixel` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-02-15 16:02:51
