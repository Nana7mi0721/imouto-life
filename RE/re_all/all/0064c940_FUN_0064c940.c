
undefined4 FUN_0064c940(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  uint local_4;
  
  puVar1 = param_1;
  iVar2 = FUN_006507c0(*param_1);
  puVar3 = &LAB_0064cb00;
  if (iVar2 == 0) {
    puVar3 = &LAB_0064cf20;
  }
  puVar1[0xc] = puVar3;
  puVar1[0xd] = 0;
  switch(*(undefined2 *)(puVar1 + 8)) {
  case 0:
  case 1:
  case 2:
    if (*(short *)(puVar1 + 6) == 8) {
      if (puVar1[3] == 1) {
        puVar1[0xd] = FUN_0064d5f0;
      }
      else if (puVar1[3] == 2) {
        iVar2 = FUN_0064dea0(puVar1);
        if (iVar2 != 0) {
          puVar1[0xd] = FUN_0064d9f0;
        }
      }
      else {
        puVar1[0xd] = FUN_0064d2f0;
      }
    }
    else if (*(short *)(puVar1 + 6) == 0x10) {
      if (puVar1[3] == 1) {
        iVar2 = FUN_0064df20(puVar1);
        if (iVar2 != 0) {
          puVar1[0xd] = &LAB_0064dbb0;
        }
      }
      else if (puVar1[3] == 2) {
        iVar2 = FUN_0064df20(puVar1);
        if ((iVar2 != 0) && (iVar2 = FUN_0064dea0(puVar1), iVar2 != 0)) {
          puVar1[0xd] = &LAB_0064dca0;
        }
      }
      else {
        iVar2 = FUN_0064df20(puVar1);
        if (iVar2 != 0) {
          puVar1[0xd] = &LAB_0064dae0;
        }
      }
    }
    break;
  case 5:
    if ((*(short *)(puVar1 + 6) == 8) && (*(short *)((int)puVar1 + 0x1a) == 4)) {
      puVar1[3] = 1;
      puVar1[0xd] = FUN_0064d8d0;
    }
    break;
  case 6:
    if ((((*(short *)(puVar1 + 6) == 8) && (*(short *)((int)puVar1 + 0x1a) == 3)) &&
        (iVar2 = FUN_0064bc60(puVar1), iVar2 != 0)) &&
       (FUN_00651280(*puVar1,0x212,&param_1,&local_4),
       (((uint)param_1 & 0xffff) << 4 | local_4 & 0xffff) == 0x11)) {
      puVar1[0xd] = &LAB_0064dde0;
    }
  }
  if ((puVar1[0xc] == 0) || (puVar1[0xd] == 0)) {
    return 0;
  }
  return 1;
}

