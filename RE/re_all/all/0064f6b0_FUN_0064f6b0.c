
int FUN_0064f6b0(undefined4 *param_1,int param_2,char *param_3)

{
  ushort uVar1;
  char *pcVar2;
  ushort uVar3;
  
  uVar1 = *(ushort *)((int)param_1 + 0x62);
  uVar3 = uVar1;
  if (param_2 != 0) {
    pcVar2 = param_3;
    while( true ) {
      if (uVar3 == 0) {
        return (int)pcVar2 - (int)param_3;
      }
      while( true ) {
        if (param_3 + param_2 <= pcVar2) goto LAB_0064f6f9;
        if (*pcVar2 == '\0') break;
        pcVar2 = pcVar2 + 1;
      }
      if (param_3 + param_2 <= pcVar2) break;
      uVar3 = uVar3 - 1;
      pcVar2 = pcVar2 + 1;
    }
  }
LAB_0064f6f9:
  FUN_006512e0(param_1[0x9d],s_TIFFSetField_00a0678c,s__s__Invalid_InkNames_value__expe_00a06948,
               *param_1,(uint)uVar1,(uint)uVar1 - (uint)uVar3);
  return 0;
}

