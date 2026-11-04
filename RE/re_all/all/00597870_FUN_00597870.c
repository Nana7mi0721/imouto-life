
undefined4 FUN_00597870(void)

{
  int iVar1;
  undefined4 unaff_ESI;
  undefined1 *puVar2;
  undefined *puVar3;
  int *local_30;
  int iStack_2c;
  int iStack_28;
  int local_24;
  int iStack_20;
  int iStack_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  DAT_00ddb368 = 0;
  local_30 = (int *)0x0;
  iVar1 = FUN_005d3710(0x80,0x80,0x80,1,0,0x16,0,&DAT_00ddb368,0);
  if (iVar1 == 0) {
    iVar1 = FUN_005d3710(0x80,0x80,0x80,1,0,0x16,2,&local_30,0);
    if (iVar1 == 0) {
      FUN_0056d380(&local_24,0,0xc);
      local_18 = 0;
      local_14 = 0;
      local_8 = 0;
      local_10 = 0x80;
      local_c = 0x80;
      local_4 = 0x80;
      iVar1 = (**(code **)(*local_30 + 0x4c))(local_30,0,&local_24,&local_18,0);
      if (iVar1 == 0) {
        iStack_28 = 0;
        iStack_2c = 0;
        while( true ) {
          do {
            iVar1 = 0;
            puVar2 = (undefined1 *)(iStack_20 * iStack_28 + local_24 * iStack_2c + iStack_1c);
            do {
              FUN_00597580(iVar1 * 2,iStack_2c * 2,iStack_28 * 2,puVar2 + 2,puVar2 + 1,puVar2);
              if (((iVar1 < 8) && (iStack_2c < 8)) && (iStack_28 < 8)) {
                *puVar2 = 0xff;
                puVar2[1] = 0xff;
                puVar2[2] = 0xff;
              }
              puVar2[3] = 0xff;
              iVar1 = iVar1 + 1;
              puVar2 = puVar2 + 4;
            } while (iVar1 < 0x80);
            iStack_2c = iStack_2c + 1;
          } while (iStack_2c < 0x80);
          iStack_28 = iStack_28 + 1;
          if (0x7f < iStack_28) break;
          iStack_2c = 0;
        }
        (**(code **)(*local_30 + 0x50))(local_30,0);
        FUN_005d3810(unaff_ESI,DAT_00ddb368);
        FUN_005d3370(unaff_ESI);
        return 0;
      }
      puVar3 = &DAT_007fa008;
    }
    else {
      puVar3 = &DAT_007fa078;
    }
  }
  else {
    puVar3 = &DAT_007fa0e8;
  }
  FUN_0056bb10(puVar3);
  if (DAT_00ddb368 != 0) {
    FUN_005d3370(DAT_00ddb368);
    DAT_00ddb368 = 0;
  }
  if (local_30 != (int *)0x0) {
    FUN_005d3370(local_30);
  }
  return 0xffffffff;
}

