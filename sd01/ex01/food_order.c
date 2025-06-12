/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   food_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:10:20 by pdessant          #+#    #+#             */
/*   Updated: 2025/06/12 11:57:25 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "food_order.h"

/* 
You’re building the backend for a food delivery app. A critical task is to process an in-
coming order. The logic changes depending on whether the restaurant is currently open
or closed. If it’s open, you create a standard order confirmation. If it’s closed, you create
a pre-order confirmation for the next day.
Your goal is to implement the control logic that, given an order request, checks the restau-
rant’s status, prepares the appropriate confirmation, and sends a notification.
*/

int process_food_order(struct OrderRequest *request)
{
    struct OrderConfirmation *confirmation;
    int status = check_restaurant_status(request);

    if (status == 1)
        confirmation = create_standard_confirmation();
     if (!confirmation)
    {
        free(request);
        return (-1);
    }

    else if (status == 0)
        confirmation = create_preorder_confirmation();
    if (!confirmation)
    {
        free(request);
        return (-1);
    }

    send_confirmation_notification(confirmation);
    return (0);
}