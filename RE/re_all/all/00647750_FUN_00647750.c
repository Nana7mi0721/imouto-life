
undefined4 FUN_00647750(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  uint local_4;
  
  puVar1 = param_1;
  iVar2 = FUN_006507c0(*param_1);
  puVar3 = &LAB_00647b20;
  if (iVar2 == 0) {
    puVar3 = &LAB_00647ea0;
  }
  puVar1[0xc] = puVar3;
  puVar1[0xd] = 0;
  switch(*(undefined2 *)(puVar1 + 8)) {
  case 0:
  case 1:
    iVar2 = FUN_0064beb0(puVar1);
    if (iVar2 != 0) {
      switch(*(undefined2 *)(puVar1 + 6)) {
      case 1:
        puVar1[0xd] = &LAB_00648580;
        break;
      case 2:
        puVar1[0xd] = &LAB_006486d0;
        break;
      case 4:
        puVar1[0xd] = &LAB_006487b0;
        break;
      case 8:
        if ((puVar1[3] == 0) || (*(short *)((int)puVar1 + 0x1a) != 2)) {
          puVar1[0xd] = &LAB_00648420;
        }
        else {
          puVar1[0xd] = &LAB_00648480;
        }
        break;
      case 0x10:
        puVar1[0xd] = FUN_00648500;
      }
    }
    break;
  case 2:
    if (*(short *)(puVar1 + 6) == 8) {
      if (puVar1[3] == 1) {
        puVar1[0xd] = &LAB_00648b50;
      }
      else if (puVar1[3] == 2) {
        iVar2 = FUN_0064dea0(puVar1);
        if (iVar2 != 0) {
          puVar1[0xd] = FUN_00648e10;
        }
      }
      else {
        puVar1[0xd] = &LAB_00648850;
      }
    }
    else if (*(short *)(puVar1 + 6) == 0x10) {
      if (puVar1[3] == 1) {
        iVar2 = FUN_0064df20(puVar1);
        if (iVar2 != 0) {
          puVar1[0xd] = FUN_00648f80;
        }
      }
      else if (puVar1[3] == 2) {
        iVar2 = FUN_0064df20(puVar1);
        if ((iVar2 != 0) && (iVar2 = FUN_0064dea0(puVar1), iVar2 != 0)) {
          puVar1[0xd] = FUN_00649030;
        }
      }
      else {
        iVar2 = FUN_0064df20(puVar1);
        if (iVar2 != 0) {
          puVar1[0xd] = FUN_00648ed0;
        }
      }
    }
    break;
  case 3:
    iVar2 = FUN_0064beb0(puVar1);
    if (iVar2 != 0) {
      switch(*(undefined2 *)(puVar1 + 6)) {
      case 1:
        puVar1[0xd] = &LAB_006482d0;
        break;
      case 2:
        puVar1[0xd] = &LAB_006481f0;
        break;
      case 4:
        puVar1[0xd] = &LAB_00648150;
        break;
      case 8:
        puVar1[0xd] = &LAB_006480f0;
      }
    }
    break;
  case 5:
    iVar2 = FUN_0064beb0(puVar1);
    if ((iVar2 != 0) && (*(short *)(puVar1 + 6) == 8)) {
      if (puVar1[0xe] == 0) {
        puVar1[0xd] = FUN_00649120;
      }
      else {
        puVar1[0xd] = FUN_00649c90;
      }
    }
    break;
  case 6:
    if (((*(short *)(puVar1 + 6) == 8) && (*(short *)((int)puVar1 + 0x1a) == 3)) &&
       (iVar2 = FUN_0064bc60(puVar1), iVar2 != 0)) {
      FUN_00651280(*puVar1,0x212,&param_1,&local_4);
      switch(((uint)param_1 & 0xffff) << 4 | local_4 & 0xffff) {
      case 0x11:
        puVar1[0xd] = &LAB_0064bbd0;
        break;
      case 0x12:
        puVar1[0xd] = &LAB_0064ba20;
        break;
      case 0x21:
        puVar1[0xd] = &LAB_0064b8c0;
        break;
      case 0x22:
        puVar1[0xd] = &LAB_0064b490;
        break;
      case 0x41:
        puVar1[0xd] = &LAB_0064b1f0;
        break;
      case 0x42:
        puVar1[0xd] = &LAB_0064ab10;
        break;
      case 0x44:
        puVar1[0xd] = &LAB_00649de0;
      }
    }
    break;
  case 8:
    iVar2 = FUN_0064beb0(puVar1);
    if ((iVar2 != 0) && (*(short *)(puVar1 + 6) == 8)) {
      uVar4 = FUN_0064bcf0(puVar1);
      puVar1[0xd] = uVar4;
    }
  }
  if ((puVar1[0xc] == 0) || (puVar1[0xd] == 0)) {
    return 0;
  }
  return 1;
}

