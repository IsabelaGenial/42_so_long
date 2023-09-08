fd = open (*argc, O_RDONLY);
if (fd != -1)
{
mlx_clear_window(world.mlx, world.win);
ft_print_map (fd, &wprld);
ft_print_objects (fd, &world);
close (fd);
}