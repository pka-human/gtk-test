#include <gtk/gtk.h>

GtkWidget *entry;

void text_changed(GtkWidget *widget, gpointer data) {
    const gchar *text = gtk_entry_get_text(GTK_ENTRY(entry));
    g_print("Text changed: %s\n", text);
}

void button1_clicked(GtkWidget *button, gpointer user_data) {
    g_print("Button 1 clicked!\n");
}

void button2_clicked(GtkWidget *button, gpointer user_data) {
    g_print("Button 2 clicked!\n");
}

void button3_clicked(GtkWidget *button, gpointer user_data) {
    g_print("Button 3 clicked!\n");
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // windows
    GtkWidget *main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(main_window), "Simple GTK Interface");
    gtk_window_set_default_size(GTK_WINDOW(main_window), 512, 512);

    // grid
    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(main_window), grid);

    // first button
    GtkWidget *button1 = gtk_button_new_with_label("Button 1");
    g_signal_connect(button1, "clicked", G_CALLBACK(button1_clicked), NULL);

    // second button
    GtkWidget *button2 = gtk_button_new_with_label("Button 2");
    g_signal_connect(button2, "clicked", G_CALLBACK(button2_clicked), NULL);

    // third button
    GtkWidget *button3 = gtk_button_new_with_label("Button 3");
    g_signal_connect(button3, "clicked", G_CALLBACK(button3_clicked), NULL);
    
    // text entry
    entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Введите текст...");
    g_signal_connect(entry, "changed", G_CALLBACK(text_changed), NULL);

    // close the window button
    GtkWidget *buttonClose = gtk_button_new_with_label("Close the window");
    g_signal_connect(buttonClose, "clicked", G_CALLBACK(gtk_main_quit), NULL);

    // size
    gtk_widget_set_size_request(button1, 120, 50);
    gtk_widget_set_size_request(button2, 120, 50);
    gtk_widget_set_size_request(button3, 120, 100);
    gtk_widget_set_size_request(buttonClose, 240, 25);

    // widgets to grid attach
    gtk_grid_attach(GTK_GRID(grid), entry, 0, 0, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button1, 0, 1, 1, 1); 
    gtk_grid_attach(GTK_GRID(grid), button2, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button3, 1, 1, 1, 2);
    gtk_grid_attach(GTK_GRID(grid), buttonClose, 0, 3, 2, 1);
  
    g_signal_connect(main_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(main_window);

    gtk_main();

    return 0;
}