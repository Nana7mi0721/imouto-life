
void FUN_00678920(int param_1,undefined2 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  
  iVar2 = param_3;
  iVar1 = param_1;
  if ((int)(uint)*(ushort *)(param_1 + 0x148) < param_3) {
    FUN_006687b0(param_1,s_Invalid_number_of_histogram_entr_00a0d7c8);
    return;
  }
  FUN_00677300(param_1,0x68495354,param_3 * 2);
  if (0 < iVar2) {
    puVar3 = param_2;
    do {
      FUN_00677270(&param_1,*puVar3);
      FUN_00677370(iVar1,&param_1,2);
      puVar3 = puVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  FUN_006773b0(iVar1);
  return;
}

