public class BadNeighbors{
    public int maxDonations(int[] donations){
        int len = donations.length;
        int i;
        if(len==2){
            if(donations[0] > donations[1])
                return donations[0];
            else
                return donations[1];
        }
        int[] val1 = new int[len];
        int[] val2 = new int[len];
        /*
        if(donations[0] > donations[1]){
        	val1[0]=donations[0];
            val1[1]=donations[0];
        }   
        else{
        	val1[0]=donations[1];
            val1[1]=donations[1];    	
        }
        */
        val1[0]=donations[0];
        val1[1]=donations[1];
        for(i=2; i<=len-2; i++){
            //val1[i] = donations[i];
            //int max = val1[i-1];
            //j=i-2;
            //while(j>=0){
        	if(val1[i-2] + donations[i] > val1[i-1])
                val1[i] = val1[i-2] + donations[i];
            else
                val1[i] = val1[i-1];
            if(i!=2){
            	if(val1[i-3] + donations[i] > val1[i])
                	val1[i] = val1[i-3] + donations[i];
            	else
                	val1[i] = val1[i];
            }
            //}
        }
        /*
        if(donations[1] > donations[2]){
        	val2[1]=donations[1];
            val2[2]=donations[1];
        }   
        else{
        	val2[1]=donations[2];
            val2[2]=donations[2];    	
        }
        */
        val2[1]=donations[1];
        val2[2]=donations[2];
        for(i=3; i<=len-1; i++){
        	if(val2[i-2]+donations[i] > val2[i-1])
                val2[i] = val2[i-2] + donations[i];
            else
                val2[i] = val2[i-1];
            if(i!=3){
            	if(val2[i-3] + donations[i] > val2[i])
                	val2[i] = val2[i-3] + donations[i];
            	else
                	val2[i] = val2[i];
            }
        }
        if(val1[len-2] > val2[len-1])
            return val1[len-2];
       	else 
            return val2[len-1];
        //return donations.length;
    }
}
