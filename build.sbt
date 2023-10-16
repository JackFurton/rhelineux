ThisBuild / version := "0.1.0-SNAPSHOT"

ThisBuild / scalaVersion := "2.13.10"

lazy val root = (project in file("."))
 .settings(
   name := "scala-web-scraping",
   libraryDependencies ++= Seq(
     "org.seleniumhq.selenium" % "selenium-java" % "4.5.0"
   )
 )

