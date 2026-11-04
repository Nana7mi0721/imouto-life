
void FUN_0064d8d0(undefined4 param_1,uint *param_2,undefined4 param_3,undefined4 param_4,int param_5
                 ,int param_6,int param_7,int param_8,byte *param_9,byte *param_10,byte *param_11,
                 byte *param_12)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint *puVar5;
  int local_4;
  
  if (param_6 != 0) {
    local_4 = param_6;
    do {
      if (param_5 != 0) {
        param_6 = param_5;
        puVar5 = param_2;
        do {
          param_2 = puVar5 + 1;
          iVar4 = 0xff - (uint)*param_12;
          param_12 = param_12 + 1;
          bVar1 = *param_9;
          bVar2 = *param_10;
          param_9 = param_9 + 1;
          param_10 = param_10 + 1;
          bVar3 = *param_11;
          param_11 = param_11 + 1;
          param_6 = param_6 + -1;
          *puVar5 = ((((0xff - (uint)bVar3) * iVar4) / 0xff | 0xffffff00) << 8 |
                    ((0xff - (uint)bVar2) * iVar4) / 0xff) << 8 |
                    ((0xff - (uint)bVar1) * iVar4) / 0xff;
          puVar5 = param_2;
        } while (param_6 != 0);
      }
      param_9 = param_9 + param_7;
      param_10 = param_10 + param_7;
      param_11 = param_11 + param_7;
      param_12 = param_12 + param_7;
      param_2 = param_2 + param_8;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  return;
}

