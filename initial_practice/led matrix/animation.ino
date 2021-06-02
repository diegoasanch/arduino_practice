
int face[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
};
int blink[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 1, 1, 1, 0},
    {0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
};

const int totalFrames = 2;

int frames[totalFrames][8][8] = {
    // { // Face
    //     {0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 1, 0, 0, 1, 0, 0},
    //     {0, 0, 1, 0, 0, 1, 0, 0},
    //     {0, 0, 1, 0, 0, 1, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 1, 0, 0, 0, 0, 1, 0},
    //     {0, 0, 1, 1, 1, 1, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0},
    // },
    // { // Blink
    //     {0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 1, 0, 0, 0, 0, 0},
    //     {0, 0, 1, 0, 1, 1, 1, 0},
    //     {0, 0, 1, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 1, 0, 0, 0, 0, 1, 0},
    //     {0, 0, 1, 1, 1, 1, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0},
    // },
    { // Heart
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 1, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
    },
    { // Heart line
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 1, 1, 0},
        {1, 0, 0, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
    },
};
