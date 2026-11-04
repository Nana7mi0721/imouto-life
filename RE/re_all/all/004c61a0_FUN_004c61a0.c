
void __fastcall FUN_004c61a0(int param_1)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  FUN_004bf5b0(0,0,0);
  FUN_004c7d60();
  FUN_004c5e60(0xfffffffe);
  FUN_004bf5b0(0,0,0);
  FUN_004c6350(0,0xffffffff);
  FUN_005160a0(DAT_00a117d0);
  FUN_004c5e60(0xffffffff);
  FUN_005160a0(0);
  FUN_004bf5b0(0,0,0);
  FUN_004ca990();
  local_14 = 0xff;
  local_10 = 0xff;
  local_c = 0xff;
  FUN_004bf5b0(0,0,&local_14);
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          while( true ) {
            FUN_005161e0(local_14,local_10,local_c);
            local_8 = FUN_004cafa0(*(undefined4 *)(param_1 + 0x9f3c));
            if (local_8 < 0) break;
            FUN_004d3c00(local_8);
            FUN_004bd8e0();
          }
          if (local_8 != -10) break;
          FUN_004bd8e0();
        }
        if (-0x14 < local_8) break;
        FUN_004c6350(1,-1000 - local_8);
      }
      if (-0xb < local_8) break;
      FUN_004d3c00(-0xb - local_8);
      FUN_004bd8e0();
    }
  } while (local_8 != -1);
  FUN_004c6350(2,0xffffffff);
  FUN_004c92b0();
  return;
}

