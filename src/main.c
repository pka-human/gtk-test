#include <gtk/gtk.h>

void pickme_clicked(GtkWidget *button, gpointer user_data) {
    g_print("pickme\n");
}

void sex_clicked(GtkWidget *button, gpointer user_data) {
    g_print("SEX SEX SEX!\n");
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // windows fuck you
    GtkWidget *main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(main_window), "Simple GTK Interface");
    gtk_window_set_default_size(GTK_WINDOW(main_window), 300, 200);

    // грид
    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(main_window), grid);

    // пикми
    GtkWidget *pickme_button = gtk_button_new_with_label("Click me");
    g_signal_connect(pickme_button, "clicked", G_CALLBACK(pickme_clicked), NULL);

    // сэкс
    GtkWidget *s_button = gtk_button_new_with_label("Sex");
    g_signal_connect(s_button, "clicked", G_CALLBACK(sex_clicked), NULL);

    // сайз
    gtk_widget_set_size_request(pickme_button, 120, 50);
    gtk_widget_set_size_request(s_button, 120, 50);

    // кнопки в грид
    gtk_grid_attach(GTK_GRID(grid), pickme_button, 0, 0, 1, 1); 
    gtk_grid_attach(GTK_GRID(grid), s_button, 1, 0, 1, 1);
  
    g_signal_connect(main_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(main_window);

    gtk_main();

    return 0;
}

