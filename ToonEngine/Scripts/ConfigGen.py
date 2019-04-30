import inspect
import os
import configparser

def main() :
	current_path = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
	root_path = os.path.join(current_path, "..")
	target_config_file = os.path.join(root_path, "Resources/engine_config.ini")

	config = configparser.ConfigParser()
	config.read(target_config_file)
	config["Common"]["root_path"] = '"{}"'.format(root_path)

	with open(target_config_file, 'w') as ini :
		config.write(ini)

if __name__ == "__main__" :
	main()