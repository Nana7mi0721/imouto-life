
void FUN_0065fcb0(int param_1,short *param_2,int param_3)

{
  short sVar1;
  int iVar2;
  uint *puVar3;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  puVar3 = *(uint **)(param_1 + 0xc);
  if (0 < param_3) {
    do {
      *param_2 = ((ushort)(*puVar3 >> 0xc) & 0xffd) + 0x3402;
      iVar2 = FUN_0065eef0(&local_18,&local_10,*puVar3 & 0x3fff);
      if (iVar2 < 0) {
        local_18 = 0xbd156c1a;
        uStack_14 = 0x3fcaf286;
        local_10 = 0x94b8199e;
        uStack_c = 0x3fde50d7;
      }
      sVar1 = __ftol();
      param_2[1] = sVar1;
      sVar1 = __ftol();
      param_2[2] = sVar1;
      param_2 = param_2 + 3;
      puVar3 = puVar3 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

