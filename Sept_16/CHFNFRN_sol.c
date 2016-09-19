

void Bip1(int V,int graph[][V],int,int c[]);
int Bip(int V,int graph[][V],int);

void Bip1(int V,int graph[][V],int s,int c[])
{int u,v,r=0,q[1001],f=0;
    c[s] = 1;
    q[r]=s;
    r++;
    while (f!=r)
    {
        u = q[f];
        f++;
        for (v = 0; v < V; v++)
        {

            if (u!=v && graph[u][v]==0 && c[v]==-1)
            {
                c[v] =1-c[u];
                q[r]=v;
                r++;
            }

        }

    }

}

int Bip(int V,int graph[][V],int s)
{
    int c[V],i,v,q[1001],a1[1500]={0},a2[1500]={0},j,ans=0,r=0,f=0,u;
    for (i = 0;i < V; i++)
        c[i] = -1;
    c[s] = 1;
    q[r]=s;
    r++;
    while (f!=r)
    {
        u = q[f];
        f++;
        for (v = 0; v < V; v++)
        {

            if (u!=v && graph[u][v]==0 && c[v] == -1)
            {
                c[v] =1-c[u];
                q[r]=v;
                r++;
            }

        }

    }
    for(i=0;i<V;i++) {   
        if(c[i]==-1)
            Bip1(V,graph,i,c);

    }
    int x=0,y=0;
    for(i=0;i<V;i++)
    {
        if(c[i]==0)
        {
            a1[x]=i;
            x++;
        }
        else if(c[i]==1)
        {
            a2[y]=i;
            y++;
        }

    }

    for(i=0;i<x;i++)
    {
        for(j=0;j<x;j++)
        {
            if(graph[a1[i]][a1[j]]==1)
                continue;
            else
            {
                ans=1;}
        }
    }
    for(i=0;i<y;i++)
    {
        for(j=0;j<y;j++)
        {
            if(graph[a2[i]][a2[j]]==1)
                continue;
            else
                ans=1;
        }
    }
    if(ans==1)
        return 0;
    else
        return 1;
}


int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,a,b,i,j,k;

        scanf("%d%d",&n,&m);
        int graph[n][n];
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                graph[i][j]=0;

            }
        }
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            graph[a-1][b-1]=1;
            graph[b-1][a-1]=1;
        }

        for(i=0;i<n;i++)
            graph[i][i]=1;



        k=Bip(n,graph,0);
        if(k==1)
            printf("YES\n");
        else
            printf("NO\n");}
    return 0;
} 
