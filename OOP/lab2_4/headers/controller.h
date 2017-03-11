#ifndef CONTROLLER_H
#define CONTROLLER_H

	unsigned char	send_reg_num_validator(unsigned long reg_num);
	unsigned char	send_category_validator(char category[10]);
	void			send_car_repository(unsigned long reg_num, char model[100], char category[10]);
	unsigned char	send_model_validator(char model[100]);

#endif