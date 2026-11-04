
int FUN_00582b00(int param_1)

{
  undefined1 local_128 [172];
  undefined1 local_7c [108];
  undefined4 local_10;
  
  if (param_1 == -2) {
    if (DAT_00dda464 < 0) {
      DAT_00dda464 = FUN_00582a10();
      FUN_00580830(DAT_00dda464,&DAT_00dda464);
      FUN_00515810(DAT_00dda464,1);
    }
    return DAT_00dda464;
  }
  if (param_1 != -1) {
    return -1;
  }
  if (DAT_00dda460 < 0) {
    FUN_00524a70(local_128);
    local_10 = 1;
    FUN_005194a0(local_7c,0x20,1,0);
    DAT_00dda460 = FUN_00529c50(local_128,0,0xffffffff,&DAT_00889ad0,0xac,0,0,1,0,0);
    FUN_00580830(DAT_00dda460,&DAT_00dda460);
    FUN_00515810(DAT_00dda460,1);
  }
  return DAT_00dda460;
}

