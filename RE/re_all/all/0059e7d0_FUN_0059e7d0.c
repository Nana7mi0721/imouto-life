
void FUN_0059e7d0(void)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  int *piVar4;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  iVar2 = 0x2c;
  puVar3 = &DAT_00a380f8;
  do {
    if ((((DAT_00cc79c0 == 0) || (uVar1 = *puVar3, (int)uVar1 < 0)) ||
        ((uVar1 & 0x7c000000) != DAT_00cc79e8)) ||
       (((DAT_00cc79f0 <= (int)(uVar1 & 0xffff) ||
         (piVar4 = *(int **)(DAT_00cc79c4 + (uVar1 & 0xffff) * 4), piVar4 == (int *)0x0)) ||
        ((*piVar4 * 0x10000 != (uVar1 & 0x3ff0000) || (piVar4[4] != 0)))))) {
      piVar4 = (int *)&DAT_0085fb08;
    }
    else {
      local_40 = piVar4[0x6b];
      local_3c = piVar4[0x6f];
      local_38 = piVar4[0x73];
      local_34 = piVar4[0x77];
      local_30 = piVar4[0x6c];
      local_2c = piVar4[0x70];
      local_28 = piVar4[0x74];
      local_24 = piVar4[0x78];
      local_20 = piVar4[0x6d];
      local_1c = piVar4[0x71];
      local_18 = piVar4[0x75];
      local_14 = piVar4[0x79];
      local_10 = piVar4[0x6e];
      local_c = piVar4[0x72];
      local_8 = piVar4[0x76];
      local_4 = piVar4[0x7a];
      piVar4 = &local_40;
    }
    FUN_0059cb80(&DAT_00ddb600,0,0,iVar2,piVar4,4,1);
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + 4;
  } while ((int)puVar3 < 0xa38104);
  return;
}

