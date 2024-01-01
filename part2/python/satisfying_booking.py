def satisfying_booking(R):
    '''
    Input:  R | Tuple of |R| talk request tuples (s, t)
    Output: B | Tuple of room booking triples (k, s, t)
              | that is the booking schedule that satisfies R
    '''
    if len(R) == 1:
        s, t = R[0]
        return ((1, s, t))
    m = len(R) // 2
    R1, R2 = R[:m], R[m:]
    B1 = satisfying_booking(R1)
    B2 = satisfying_booking(R2)
    B = merge_bookings(B1, B2)
    return tuple(B)

def merge_bookings(booking_one, booking_two):
    booking_one_length = len(booking_one)
    booking_two_length = len(booking_two)
    index_one = 0
    index_two = 0

    current_time = 0
    B = []

    # loop until the end of both of the booking
    while index_one + index_two < booking_one_length + booking_two_length:
        # 4 condition still left in booking_one, still left in booking_two
        # and there's left only in one of those bookings.
        # or still left in both of those bookings

        if index_one < booking_one_length:
            # still left in booking_one
            room_one, start_one, end_one = booking_one[index_one]

        if index_two < booking_two_length:
            # still left in booking_two
            room_two, start_two, end_two = booking_two[index_two]

        if index_two == booking_two_length:
            # only left in the booking_one
            room_append, start_append, end_append = room_one, max(current_time, start_one), end_one
        elif index_one == booking_one_length:
            # only left in the booking_two
            room_append, start_append, end_append = room_two, max(current_time, start_two), end_two

        else:
            # still left in both of those bookings
            # we have to choose which one we want to append first to the B

            if current_time < min(start_one, start_two):
                # current_time to the lowest start_time rn in two of those.
                # current_time may be start_one's or start_two's
                current_time = min(start_one, start_two)

            # firstly determined by the end times of two bookings
            if end_one <= start_two:
                # we used current_time we can just use start_one
                # but we like to complicate things.
                # if the end time of booking_one's talk is less than start time of booking_two's talk
                # we definitely wants to append the booking_one's talk first. 
                room_append, start_append, end_append = room_one, current_time, end_one
                # now countup the index of booking_one
                index_one += 1
            elif end_two <= start_one:
                # now we will append the booking_two's talk
                room_append, start_append, end_append = room_two, current_time, end_two
                # now countup the conter
                index_two += 1
            # now determined by the current_time if the above two case didn't work.
            elif current_time < start_two:
                # use the booking one's room and current time and end time as the start of the start_two
                room_append, start_append, end_append = room_one, current_time, start_two
            elif current_time < start_one:
                room_append, start_append, end_append = room_two, current_time, start_one

            else:
                # the two times are the same collision
                # choose one that is the same as the current time
                room_append, start_append, end_append = room_one + room_two, current_time, min(end_one, end_two)
                if end_one == current_time:
                    index_one += 1
                if end_two == current_time:
                    index_two += 1

        B.append((room_append, start_append, end_append))
    B_ = [B[0]]
    for room_append, start_append, end_append in B[1:]:
        room_append_, start_append_, end_append_ = B_[-1]
        if (room_append == room_append_) and (end_append_ == start_append):
            B_.pop()
            start_append = start_append_
        B_.append((room_append, start_append, end_append))
    return B_
