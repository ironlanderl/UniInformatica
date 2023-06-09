def format_question(question):
    if len(question) < 50:
        question = question + " " * (50 - len(question))
    elif len(question) > 50:
        question = question[:50]
    return question

filename = "20220630-02.txt"  # Sostituisci con il nome del tuo file

with open(filename, "r") as file:
    for line in file:
        line = line.strip()
        code = line[:4]
        rest_of_line = line[4:]
        question_end_index = rest_of_line.rfind("?") + 1
        question = rest_of_line[:question_end_index]
        answer = rest_of_line[question_end_index:].strip()
        formatted_question = format_question(question)
        print(f"{code}{formatted_question} {answer}")
