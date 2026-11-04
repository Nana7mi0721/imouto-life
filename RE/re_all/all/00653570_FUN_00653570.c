
int FUN_00653570(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0x298) = 0;
  if ((*(int *)(param_1 + 0x290) == 0) || (*(int *)(param_1 + 0x294) == 0)) {
    iVar1 = FUN_00650c00(param_1,param_3,4,"for fields array");
  }
  else {
    iVar1 = FUN_00650ba0(param_1,*(int *)(param_1 + 0x290),*(int *)(param_1 + 0x294) + param_3,4,
                         "for fields array");
  }
  *(int *)(param_1 + 0x290) = iVar1;
  if (iVar1 == 0) {
    FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"_TIFFMergeFields",
                 s_Failed_to_allocate_fields_array_00a09aa8);
    return 0;
  }
  if (param_3 != 0) {
    iVar1 = param_3;
    do {
      iVar2 = FUN_00653760(param_1,*param_2,0);
      if (iVar2 == 0) {
        *(undefined4 **)(*(int *)(param_1 + 0x290) + *(int *)(param_1 + 0x294) * 4) = param_2;
        *(int *)(param_1 + 0x294) = *(int *)(param_1 + 0x294) + 1;
      }
      param_2 = param_2 + 9;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  _qsort(*(void **)(param_1 + 0x290),*(size_t *)(param_1 + 0x294),4,(_PtFuncCompare *)&LAB_00653650)
  ;
  return param_3;
}

