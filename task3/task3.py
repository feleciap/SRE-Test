import json 
 
def read_json(file_path): 

    with open(file_path, 'r') as file: 
        data = json.load(file) 
    return data 
 
def write_json(data, file_path): 

    with open(file_path, 'w') as file: 
        json.dump(data, file, indent=4) 
 
def fill_values(tests, values): 

    for key, value in tests.items(): 
        if isinstance(value, dict): 
            fill_values(value, values) 
        elif isinstance(value, str) and key == "id": 
            test_id = int(value) 
            for val in values: 
                if val['id'] == test_id: 
                    tests[key] = val['value'] 
                    break 
 
if __name__ == "__main__": 
    import sys 
    if len(sys.argv) != 4: 
        print("Ошибка: необходимо ввести 3 пути к файлам: values.json و tests.json و report.json") 
        sys.exit(1) 
 
    values_file = sys.argv[1] 
    tests_file = sys.argv[2] 
    report_file = sys.argv[3] 
 
    values = read_json(values_file) 
    tests = read_json(tests_file) 
 
    fill_values(tests, values) 
 
    write_json(tests, report_file) 
 
    print(" Файл report.json был успешно создан.")