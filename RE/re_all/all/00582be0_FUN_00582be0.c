
void FUN_00582be0(void)

{
  undefined1 local_128 [172];
  undefined4 local_7c [27];
  undefined4 local_10;
  undefined4 local_8;
  
  FUN_00524a70(local_128);
  local_10 = 0;
  local_8 = 0;
  FUN_005194a0(local_7c,0x20,1,0);
  local_7c[0] = 0xff00ff;
  DAT_00dda458 = FUN_00529c50(local_128,0,0xffffffff,&DAT_00889978,0x54,0,0,1,0,0);
  DAT_00dda45c = FUN_00529c50(local_128,0,0xffffffff,&DAT_008899d0,0x4c,0,0,1,0,0);
  FUN_00580830(DAT_00dda458,&DAT_00dda458);
  FUN_00580830(DAT_00dda45c,&DAT_00dda45c);
  FUN_00515810(DAT_00dda458,1);
  FUN_00515810(DAT_00dda45c,1);
  return;
}

