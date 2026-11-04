
void FUN_00683e90(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  char cVar3;
  uint uVar4;
  
  iVar1 = param_1[5];
  if ((iVar1 == 0x65) || (iVar1 == 0x66)) {
    if ((uint)param_1[0x3e] < (uint)param_1[8]) {
      *(undefined4 *)(*param_1 + 0x14) = 0x45;
      (**(code **)*param_1)(param_1);
    }
    (**(code **)(param_1[0x5e] + 8))(param_1);
  }
  else if (iVar1 != 0x67) {
    *(undefined4 *)(*param_1 + 0x14) = 0x15;
    *(int *)(*param_1 + 0x18) = param_1[5];
    (**(code **)*param_1)(param_1);
  }
  puVar2 = (undefined4 *)param_1[0x5e];
  cVar3 = *(char *)((int)puVar2 + 0xd);
  while (cVar3 == '\0') {
    (*(code *)*puVar2)(param_1);
    uVar4 = 0;
    if (param_1[0x44] != 0) {
      do {
        if (param_1[2] != 0) {
          *(uint *)(param_1[2] + 4) = uVar4;
          *(int *)(param_1[2] + 8) = param_1[0x44];
          (**(code **)param_1[2])(param_1);
        }
        cVar3 = (**(code **)(param_1[0x61] + 4))(param_1,0);
        if (cVar3 == '\0') {
          *(undefined4 *)(*param_1 + 0x14) = 0x19;
          (**(code **)*param_1)(param_1);
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < (uint)param_1[0x44]);
    }
    (**(code **)(param_1[0x5e] + 8))(param_1);
    puVar2 = (undefined4 *)param_1[0x5e];
    cVar3 = *(char *)((int)puVar2 + 0xd);
  }
  (**(code **)(param_1[0x62] + 0xc))(param_1);
  (**(code **)(param_1[6] + 0x10))(param_1);
  FUN_00684810(param_1);
  return;
}

