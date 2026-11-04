
void FUN_00694960(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0xc);
  param_1[99] = (int)puVar2;
  *puVar2 = FUN_0065f670;
  switch(param_1[10]) {
  case 1:
    if (param_1[9] != 1) {
      *(undefined4 *)(*param_1 + 0x14) = 10;
      (**(code **)*param_1)(param_1);
    }
    break;
  case 2:
    if (param_1[9] != 3) {
LAB_006949e5:
      *(undefined4 *)(*param_1 + 0x14) = 10;
      (**(code **)*param_1)(param_1);
    }
    break;
  case 3:
    if (param_1[9] != 3) {
      *(undefined4 *)(*param_1 + 0x14) = 10;
      (**(code **)*param_1)(param_1);
    }
    break;
  case 4:
  case 5:
    if (param_1[9] != 4) {
      *(undefined4 *)(*param_1 + 0x14) = 10;
      (**(code **)*param_1)(param_1);
    }
    break;
  default:
    if (param_1[9] < 1) goto LAB_006949e5;
  }
  if ((param_1[0x3d] != 0) && (param_1[0x14] != 2)) {
    *(undefined4 *)(*param_1 + 0x14) = 0x1c;
    (**(code **)*param_1)(param_1);
  }
  switch(param_1[0x14]) {
  case 1:
    if (param_1[0x13] != 1) {
      *(undefined4 *)(*param_1 + 0x14) = 0xb;
      (**(code **)*param_1)(param_1);
    }
    iVar1 = param_1[10];
    if ((iVar1 == 1) || (iVar1 == 3)) {
      puVar2[1] = FUN_006950b0;
      return;
    }
    if (iVar1 == 2) {
      *puVar2 = &LAB_00694bf0;
      puVar2[1] = &LAB_00694e00;
      return;
    }
    break;
  case 2:
    if (param_1[0x13] != 3) {
      *(undefined4 *)(*param_1 + 0x14) = 0xb;
      (**(code **)*param_1)(param_1);
    }
    if (param_1[10] != 2) {
      *(undefined4 *)(*param_1 + 0x14) = 0x1c;
      (**(code **)*param_1)(param_1);
      return;
    }
    if (param_1[0x3d] == 0) {
      puVar2[1] = FUN_00695120;
      return;
    }
    if (param_1[0x3d] == 1) {
      puVar2[1] = FUN_00695000;
      return;
    }
    goto LAB_00694aa0;
  case 3:
    if (param_1[0x13] != 3) {
      *(undefined4 *)(*param_1 + 0x14) = 0xb;
      (**(code **)*param_1)(param_1);
    }
    if (param_1[10] == 2) {
      *puVar2 = &LAB_00694bf0;
      puVar2[1] = &LAB_00694cd0;
      return;
    }
    if (param_1[10] == 3) goto LAB_00694bb3;
LAB_00694aa0:
    *(undefined4 *)(*param_1 + 0x14) = 0x1c;
    (**(code **)*param_1)(param_1);
    return;
  case 4:
    if (param_1[0x13] != 4) {
      *(undefined4 *)(*param_1 + 0x14) = 0xb;
      (**(code **)*param_1)(param_1);
    }
    if (param_1[10] != 4) {
      *(undefined4 *)(*param_1 + 0x14) = 0x1c;
      (**(code **)*param_1)(param_1);
      return;
    }
    goto LAB_00694bb3;
  case 5:
    if (param_1[0x13] != 4) {
      *(undefined4 *)(*param_1 + 0x14) = 0xb;
      (**(code **)*param_1)(param_1);
    }
    if (param_1[10] == 4) {
      *puVar2 = &LAB_00694bf0;
      puVar2[1] = &LAB_00694e90;
      return;
    }
    if (param_1[10] == 5) goto LAB_00694bb3;
    break;
  default:
    if ((param_1[0x14] != param_1[10]) || (param_1[0x13] != param_1[9])) {
      *(undefined4 *)(*param_1 + 0x14) = 0x1c;
      (**(code **)*param_1)(param_1);
    }
LAB_00694bb3:
    puVar2[1] = FUN_006951b0;
    return;
  }
  *(undefined4 *)(*param_1 + 0x14) = 0x1c;
  (**(code **)*param_1)(param_1);
  return;
}

