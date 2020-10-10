


def parse_message(message): # This will be used by client and server to send parsed messagess
    HEAD  = len(message)
    return str(HEAD)+":"+message
