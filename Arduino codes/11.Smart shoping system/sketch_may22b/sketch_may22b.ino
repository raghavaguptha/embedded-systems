#include<EEPROM.h>
const char* product[5] = {"Oil",
                          "Sugar",
                          "Rice",
                          "Salt",
                          "Drink"
                         };


#define select 8

int option = 0;

int total_cost = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(select, INPUT_PULLUP);
}

void loop()
{
  if (Serial.available() > 0)
  {
    char cmd = Serial.read();
    if (cmd == 'e' || cmd == 'E')
    {
      Serial.println("Edit your product costs"); delay(1000);
      update_costings();
    }
    else if (cmd == 'S' || cmd == 's')
    {
      Serial.println("Shoping started");
      start_shoping();
    }
    else if (cmd == 'C' || cmd == 'c')
    {
      Serial.println("check product details");
      check_product_details();
    }
    else
    {
      Serial.println("Invalid Commad");
    }
  }
}


void update_costings()
{
st:
  Serial.println("Enter prodcut number");
  while (1)
  {
    if (Serial.available() > 0)
    {
      int product_num = Serial.parseInt();
      Serial.println(product_num);

      if (product_num > 0 && product_num <= 5)
      {
        Serial.println("Enter cost"); delay(1000);
        while (!Serial.available());
        int cost = Serial.parseInt();
        Serial.println("Enterd cost:" + String(cost));
        EEPROM.write(product_num - 1, cost); delay(10);
        goto st;
      }

      if (product_num > 5)
      {
        Serial.println("Invalid Product number"); delay(1000);
        goto st;
      }

      if (product_num == 0)
      {
        break;
      }
    }
  }
}


void check_product_details()
{
check:
  Serial.println("Enter product number");
  while (1)
  {
    if (Serial.available() > 0)
    {
      int num = Serial.parseInt();

      if (num <= 5 && num > 0)
      {
        Serial.print("Product Name:"); Serial.print(product[num - 1]);  Serial.println();
        Serial.print("Product Cost:"); Serial.print(EEPROM.read(num - 1));  Serial.println();
        goto check;
      }
      if (num > 5)
      {
        Serial.println("Invalid Product number"); delay(1000);
        goto check;
      }

      if (num == 0)
      {
        break;
      }
    }
  }
}


void start_shoping()
{
shop:
  Serial.println("Enter product number");
  while (1)
  {
    if (digitalRead(select) == LOW)
    {
      while (digitalRead(select) == LOW);
      option = ~option;
      Serial.println(option);
    }
    if (Serial.available() > 0)
    {
      int num = Serial.parseInt();
      if (num > 0 && num <= 5)
      {
        if(option == 0)
        {
        Serial.print(product[num - 1]); Serial.println("  Added");
        total_cost =  total_cost + EEPROM.read(num - 1);
        goto shop;
        }

        if(option == -1)
        {
        Serial.print(product[num - 1]); Serial.println("  Removed");
        total_cost = EEPROM.read(num - 1) - total_cost;
        goto shop;
        }
      }
      if (num > 5)
      {
        Serial.println("Invalid product number");
        goto shop;
      }
      if (num == 0)
      {
        Serial.println("Total_cost:" + String(total_cost) + "$");
        Serial.println("Phone pay number:1234567890");
        Serial.println("Thank you for shoping... ");
      }
    }

  }
}
