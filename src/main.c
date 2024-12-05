#include <gtk/gtk.h>

static void text_changed(GtkWidget *entry, gpointer data) {
    g_print("Text changed: %s\n", gtk_entry_get_text(GTK_ENTRY(entry)));
}

static void set_theme(GtkWidget *button, const gchar *theme_name, gpointer data) {
    g_object_set(gtk_settings_get_default(), "gtk-theme-name", theme_name, NULL);
    g_print("Theme changed to: %s\n", theme_name);
}

static gchar* get_current_theme() {
    GtkSettings *settings = gtk_settings_get_default();
    gchar *theme_name;
    g_object_get(settings, "gtk-theme-name", &theme_name, NULL);
    return theme_name;
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Simple GTK Interface");
    gtk_window_set_default_size(GTK_WINDOW(window), 512, 512);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    GtkWidget *entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Type something...");
    g_signal_connect(entry, "changed", G_CALLBACK(text_changed), NULL);
    gtk_grid_attach(GTK_GRID(grid), entry, 0, 0, 2, 1);

    gchar *current_theme = get_current_theme();
    gchar *button_label = g_strdup_printf("Default (%s)", current_theme);
    GtkWidget *button1 = gtk_button_new_with_label(button_label);
    g_signal_connect(button1, "clicked", G_CALLBACK(set_theme), current_theme);
    gtk_widget_set_size_request(button1, 120, 50);
    gtk_grid_attach(GTK_GRID(grid), button1, 0, 1, 1, 1);

    GtkWidget *button2 = gtk_button_new_with_label("Win32");
    g_signal_connect(button2, "clicked", G_CALLBACK(set_theme), "win32");
    gtk_widget_set_size_request(button2, 120, 50);
    gtk_grid_attach(GTK_GRID(grid), button2, 0, 2, 1, 1);

    GtkWidget *button3 = gtk_button_new_with_label("HighContrastInverse");
    g_signal_connect(button3, "clicked", G_CALLBACK(set_theme), "HighContrastInverse");
    gtk_widget_set_size_request(button3, 120, 100);
    gtk_grid_attach(GTK_GRID(grid), button3, 1, 1, 1, 2);

    GtkWidget *buttonClose = gtk_button_new_with_label("Close");
    g_signal_connect(buttonClose, "clicked", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_set_size_request(buttonClose, 240, 25);
    gtk_grid_attach(GTK_GRID(grid), buttonClose, 0, 3, 2, 1);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
