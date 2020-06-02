// stock Data: Imagine you are building some sort of service that will be called by up to 1,000 client
applications to get simple end-of-day stock price information (open, close, high, low). You may
assume that you already have the data, and you can store it in any format you wish. How would
you design the client-facing service that provides the information to client applications? You are
responsible for the development, rollout, and ongoing monitoring and maintenance of the feed.
Describe the different methods you considered and why you would recommend your approach.
Your service can use any technologies you wish, and can distribute the information to the client
applications in any mechanism you choose.

Ans:   
Client Ease of Use: We want the service to be easy for the clients to implement and useful for them.

Ease for Ourselves: This service should be as easy as possible for us to implement, as we shouldn't impose unnecessary work on ourselves. We need to consider in this not only the cost of implementing, but also the cost of maintenance.
Flexibility for Future Demands: This problem is stated in a "what would you do in the real world" way, so we should think like we would in a real-world problem. Ideally, we do not want to overly constrain ourselves in the implementation, such that we can't be flexible if the requirements or demands change.

• Scalability and E iciency: We should be mindful of the efficiency of our solution, so as not to overly burden our service.

#1 text file
#2 sql database
#3 xml formate