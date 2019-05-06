import inspect
import os
import configparser

def main() :
	current_path = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
	root_path = os.path.join(current_path, "..")
	target_config_file = os.path.join(root_path, "Resources/engine_config2.ini")

	config = configparser.ConfigParser()
	config['Common'] = {
		'root_path' : '"{}"'.format(root_path),
		'log_path' : '"\Log"'
	}
	config['RenderSystem'] = {
		'window_title' : '"ToonEngine Version 0.0.1"',
		'client_width' : 1200,
		'client_height' : 900,
		'default_fullscreen' : 'false'
	}

	with open(target_config_file, 'w') as ini :
		config.write(ini)
		

if __name__ == "__main__" :
	main()