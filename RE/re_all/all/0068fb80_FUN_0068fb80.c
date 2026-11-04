
void FUN_0068fb80(int *param_1,char param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  puVar1 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x40);
  param_1[0x5f] = (int)puVar1;
  *puVar1 = &LAB_0068fc10;
  if ((char)param_1[0x34] == '\0') {
    if (param_2 != '\0') {
      *(undefined4 *)(*param_1 + 0x14) = 3;
      (**(code **)*param_1)(param_1);
      return;
    }
    iVar3 = 0;
    if (0 < param_1[0x13]) {
      piVar4 = (int *)(param_1[0x15] + 0xc);
      puVar1 = puVar1 + 6;
      do {
        uVar2 = (**(code **)(param_1[1] + 8))(param_1,1,piVar4[6] * piVar4[4],piVar4[7] * *piVar4);
        *puVar1 = uVar2;
        iVar3 = iVar3 + 1;
        puVar1 = puVar1 + 1;
        piVar4 = piVar4 + 0x16;
      } while (iVar3 < param_1[0x13]);
    }
  }
  return;
}

