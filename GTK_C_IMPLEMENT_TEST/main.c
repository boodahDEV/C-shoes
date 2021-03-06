#include <gtk/gtk.h>

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Hello World\n");
}

static void activate (GtkApplication* app, gpointer user_data)
{
  GtkWidget *window;
  GtkWidget *button,*button1, *button2, *button3,*button4;
  GtkWidget *button_box;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "MyFristAPP");
  gtk_window_set_default_size (GTK_WINDOW (window), 550, 300);

  button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add (GTK_CONTAINER (window), button_box);

  button = gtk_button_new_with_label ("Hello World");
  button1 = gtk_button_new_with_label ("1");
  button2 = gtk_button_new_with_label ("2");
  button3 = gtk_button_new_with_label ("3");
  button4 = gtk_button_new_with_label ("4");

  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);

  gtk_container_add(GTK_CONTAINER (button_box), button);
  gtk_container_add(GTK_CONTAINER (button_box),button1);
  gtk_container_add(GTK_CONTAINER (button_box), button2);
  gtk_container_add(GTK_CONTAINER (button_box), button3);
  gtk_container_add(GTK_CONTAINER (button_box), button4);

  gtk_widget_show_all (window);


}

int main (int argc, char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.myfirstapp", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
