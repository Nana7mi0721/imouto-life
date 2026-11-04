
undefined4 FUN_005f6240(int *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  
  puVar1 = (undefined4 *)param_1[6];
  uVar4 = (**(code **)puVar1[9])(((undefined4 *)puVar1[9])[6]);
  uVar2 = puVar1[10];
  iVar3 = (((int)uVar2 >> 0x1f) - (int)((ulonglong)uVar4 >> 0x20)) - (uint)(uVar2 < (uint)uVar4);
  if ((iVar3 < 1) && ((iVar3 < 0 || (uVar2 - (uint)uVar4 < 0x1000)))) {
    iVar3 = (**(code **)puVar1[9])(((undefined4 *)puVar1[9])[6]);
    iVar3 = puVar1[10] - iVar3;
    if (iVar3 != 0) goto LAB_005f6288;
  }
  else {
    iVar3 = 0x1000;
LAB_005f6288:
    (**(code **)(puVar1[9] + 8))(puVar1[7],iVar3,1,*(undefined4 *)(puVar1[9] + 0x18));
    if (iVar3 != 0) goto LAB_005f62de;
  }
  if (*(char *)(puVar1 + 8) != '\0') {
    *(undefined4 *)(*param_1 + 0x14) = 0x2b;
    (**(code **)*param_1)(param_1);
  }
  *(undefined4 *)(*param_1 + 0x14) = 0x7b;
  (**(code **)(*param_1 + 4))(param_1,0xffffffff);
  iVar3 = 2;
  *(undefined1 *)puVar1[7] = 0xff;
  *(undefined1 *)(puVar1[7] + 1) = 0xd9;
LAB_005f62de:
  puVar1[1] = iVar3;
  *puVar1 = puVar1[7];
  *(undefined1 *)(puVar1 + 8) = 0;
  return CONCAT31((int3)((uint)puVar1[7] >> 8),1);
}

