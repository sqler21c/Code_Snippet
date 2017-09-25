"""
    This is about module comment
"""
def print_lol(the_list):
    """
        this is about funciton commnet
    """
    for each_item in the_list:
        if isinstance(each_item, list):
            print_lol(each_item)
        else:
            print(each_item)
