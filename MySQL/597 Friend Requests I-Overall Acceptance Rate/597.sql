# 70%

select ifnull(round((select count(distinct requester_id, accepter_id) from request_accepted) / (select count(distinct send_to_id, sender_id) from friend_request), 2), 0.00) as accept_rate;