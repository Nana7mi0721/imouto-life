
void FUN_0079b420(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  int local_18;
  undefined4 local_14;
  int local_10;
  int local_4;
  
  local_4 = FUN_007a2170(param_1,&DAT_00837788,8);
  local_10 = local_4 / 5;
  puVar7 = &local_14;
  iVar5 = 2;
  local_4 = local_4 % 5;
  do {
    uVar1 = FUN_007a2170(param_1,&DAT_008377e4,8);
    puVar7[-1] = uVar1;
    uVar1 = FUN_007a2170(param_1,&DAT_008377ec,8);
    *puVar7 = uVar1;
    puVar7 = puVar7 + 3;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar5 = 2;
  piVar2 = &local_18;
  piVar6 = param_2;
  do {
    iVar3 = *piVar2 + piVar2[2] * 3;
    *piVar2 = iVar3;
    uVar4 = (int)*(short *)(&DAT_0083776a + iVar3 * 2) - (int)*(short *)(&DAT_00837768 + iVar3 * 2);
    iVar5 = iVar5 + -1;
    *piVar6 = (int)(short)((short)((uVar4 & 0xffff) * 0x199a >> 0x10) +
                          (short)(uVar4 >> 0x10) * 0x199a) * (int)(short)((short)piVar2[1] * 2 + 1)
              + (int)*(short *)(&DAT_00837768 + iVar3 * 2);
    piVar2 = piVar2 + 3;
    piVar6 = piVar6 + 1;
  } while (iVar5 != 0);
  *param_2 = *param_2 - param_2[1];
  return;
}

