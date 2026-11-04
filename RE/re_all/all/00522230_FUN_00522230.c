
uint FUN_00522230(float param_1,float param_2,float param_3)

{
  float fVar1;
  int *piVar2;
  uint uVar3;
  float10 fVar4;
  
  uVar3 = FUN_0051c270();
  if (((((int)uVar3 < 0) || ((uVar3 & 0x7c000000) != 0x2c000000)) || (0xfff < (uVar3 & 0xffff))) ||
     ((piVar2 = (int *)(&DAT_00a38e44)[uVar3 & 0xffff], piVar2 == (int *)0x0 ||
      (*piVar2 * 0x10000 != (uVar3 & 0x3ff0000))))) {
    return 0xffffffff;
  }
  piVar2[2] = 3;
  fVar4 = (float10)FUN_00586140(&param_1,&param_1);
  fVar4 = (float10)FUN_0056d670((float)fVar4);
  fVar1 = (float)fVar4;
  piVar2[0x12] = (int)(param_1 / fVar1);
  piVar2[0x13] = (int)(param_2 / fVar1);
  piVar2[0x14] = (int)(param_3 / fVar1);
  return uVar3;
}

