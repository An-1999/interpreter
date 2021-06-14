#tivI n
#mutq <- n
#
#tivI s = 1
#ete(n >= 0) ->
#    cikl (n != 0) ->
#        s = (s * n)
#        n = (n - 1)
#        ete (n == 1) ->
#            elq -> [hjnu]
#        <-
#    elq -> 1
#    <-
#    elq -> 1
#<-
#elq -> s


tivI w
mutq <- w
tivI s = 1
tivI i = 1
tivI n = i
cikl (i != (w + 1) ->
    n = i
    ete(n > 0) ->
         s = 1
        cikl (n > 0) ->
            s = (s * n)
            n = (n - 1)
        <-
    elq -> s
    <-
    i = (i + 1)
 <-
