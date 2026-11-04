
void FUN_0068caf0(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x1c);
  param_1[0x6f] = (int)puVar1;
  *puVar1 = FUN_0065f670;
  switch(param_1[10]) {
  case 1:
    if (param_1[9] != 1) {
LAB_0068cb5b:
      *(undefined4 *)(*param_1 + 0x14) = 0xb;
      (**(code **)*param_1)(param_1);
    }
    break;
  case 2:
  case 3:
    if (param_1[9] != 3) {
      *(undefined4 *)(*param_1 + 0x14) = 0xb;
      (**(code **)*param_1)(param_1);
    }
    break;
  case 4:
  case 5:
    if (param_1[9] != 4) {
      *(undefined4 *)(*param_1 + 0x14) = 0xb;
      (**(code **)*param_1)(param_1);
    }
    break;
  default:
    if (param_1[9] < 1) goto LAB_0068cb5b;
  }
  if ((param_1[0x43] != 0) && (param_1[10] != 2)) {
    *(undefined4 *)(*param_1 + 0x14) = 0x1c;
    (**(code **)*param_1)(param_1);
  }
  iVar2 = param_1[0xb];
  if (iVar2 == 1) {
    iVar2 = param_1[10];
    param_1[0x19] = 1;
    if ((iVar2 == 1) || (iVar2 == 3)) {
      puVar1[1] = &LAB_0068d340;
      iVar2 = 1;
      if (1 < param_1[9]) {
        iVar3 = 0x58;
        do {
          iVar2 = iVar2 + 1;
          *(undefined1 *)(param_1[0x31] + 0x34 + iVar3) = 0;
          iVar3 = iVar3 + 0x58;
        } while (iVar2 < param_1[9]);
      }
      goto LAB_0068cd25;
    }
    if (iVar2 == 2) {
      if (param_1[0x43] == 0) {
        puVar1[1] = FUN_0068cfb0;
        FUN_0068cf50(param_1);
      }
      else if (param_1[0x43] == 1) {
        puVar1[1] = &LAB_0068d130;
        FUN_0068cf50(param_1);
      }
      else {
        *(undefined4 *)(*param_1 + 0x14) = 0x1c;
        (**(code **)*param_1)(param_1);
        FUN_0068cf50(param_1);
      }
      goto LAB_0068cd25;
    }
LAB_0068cc65:
    *(undefined4 *)(*param_1 + 0x14) = 0x1c;
    (**(code **)*param_1)(param_1);
  }
  else {
    if (iVar2 == 2) {
      iVar2 = param_1[10];
      param_1[0x19] = 3;
      if (iVar2 == 3) {
        puVar1[1] = &LAB_0068ce20;
        FUN_0068cd60(param_1);
        goto LAB_0068cd25;
      }
      if (iVar2 == 1) {
        puVar1[1] = &LAB_0068d370;
        goto LAB_0068cd25;
      }
      if (iVar2 == 2) {
        if (param_1[0x43] == 0) {
          puVar1[1] = FUN_0068d220;
          goto LAB_0068cd25;
        }
        if (param_1[0x43] == 1) {
          puVar1[1] = FUN_0068d080;
          goto LAB_0068cd25;
        }
        goto LAB_0068cc65;
      }
    }
    else {
      if (iVar2 == 4) {
        param_1[0x19] = 4;
        if (param_1[10] == 5) {
          puVar1[1] = &LAB_0068d3e0;
          FUN_0068cd60(param_1);
        }
        else if (param_1[10] == 4) {
          puVar1[1] = FUN_0068d2b0;
        }
        else {
          *(undefined4 *)(*param_1 + 0x14) = 0x1c;
          (**(code **)*param_1)(param_1);
        }
        goto LAB_0068cd25;
      }
      if (iVar2 == param_1[10]) {
        param_1[0x19] = param_1[9];
        puVar1[1] = FUN_0068d2b0;
        goto LAB_0068cd25;
      }
    }
    *(undefined4 *)(*param_1 + 0x14) = 0x1c;
    (**(code **)*param_1)(param_1);
  }
LAB_0068cd25:
  if (*(char *)((int)param_1 + 0x4a) == '\0') {
    param_1[0x1a] = param_1[0x19];
    return;
  }
  param_1[0x1a] = 1;
  return;
}

