package dev.draft

import org.openqa.selenium.WebDriver
import org.openqa.selenium.firefox.FirefoxDriver
import org.openqa.selenium.firefox.FirefoxOptions
import org.openqa.selenium.By


object RetScraper {
  def main(args: Array[String]): Unit = {
    System.setProperty("webdriver.gecko.driver", "geckodriver")
    val firefoxOptions = new FirefoxOptions()
    firefoxOptions.setHeadless(true)
    val driver: WebDriver = new FirefoxDriver()
    driver.get("https://twitter.com/AoretSC2")
    val tweets = driver.findElements(By.cssSelector(".tweet-text"))
    tweets.forEach(tweet => println(tweet.getText))
    driver.quit()
  }
}
