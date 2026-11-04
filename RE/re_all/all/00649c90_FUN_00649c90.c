
void FUN_00649c90(int param_1,uint *param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int param_6,int param_7,int param_8,byte *param_9)

{
  ushort uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  
  uVar1 = *(ushort *)(param_1 + 0x1a);
  iVar2 = *(int *)(param_1 + 0x38);
  if (param_6 != 0) {
    do {
      puVar3 = param_2;
      if (param_5 != 0) {
        param_1 = param_5;
        do {
          uVar4 = 0xff - param_9[3] & 0xffff;
          puVar3 = param_2 + 1;
          *param_2 = ((*(byte *)(((int)((0xff - (uint)param_9[2]) * uVar4) / 0xff & 0xffffU) + iVar2
                                ) | 0xffffff00) << 8 |
                     (uint)*(byte *)(((int)((0xff - (uint)param_9[1]) * uVar4) / 0xff & 0xffffU) +
                                    iVar2)) << 8 |
                     (uint)*(byte *)(((int)((0xff - (uint)*param_9) * uVar4) / 0xff & 0xffffU) +
                                    iVar2);
          param_9 = param_9 + uVar1;
          param_1 = param_1 + -1;
          param_2 = puVar3;
        } while (param_1 != 0);
      }
      param_9 = param_9 + (uint)uVar1 * param_7;
      param_2 = puVar3 + param_8;
      param_6 = param_6 + -1;
    } while (param_6 != 0);
  }
  return;
}

