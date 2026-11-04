
int __thiscall
FUN_0063f770(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar2 = 0;
  iVar3 = 0;
  local_4 = 0;
  puVar4 = (undefined4 *)(param_1 + 0x33c);
  do {
    if ((puVar4[4] != 0) || (*(char *)(param_1 + 0x308 + iVar2) != '\0')) {
      local_8 = puVar4[4];
      local_c = *puVar4;
      local_10 = puVar4[-4];
      local_24 = *(undefined4 *)(param_1 + 0x300);
      local_14 = *(undefined1 *)(iVar2 + 0x308 + param_1);
      local_1c = *(undefined4 *)(param_1 + 0x304);
      local_34 = puVar4[-0x18];
      local_20 = *(undefined4 *)(param_1 + 0x2fc);
      local_38 = puVar4[-0x1c];
      local_2c = puVar4[-8];
      local_30 = puVar4[-0xc];
      local_18 = 0;
      local_48 = puVar4[0x32];
      local_28 = 0;
      local_44 = puVar4[0x36];
      local_3c = 0;
      local_40 = puVar4[0x3a];
      iVar1 = FUN_0063ff80(&local_38,param_3,param_4,param_5,param_6,param_7,param_8,param_2,iVar3,
                           &local_48,0);
      iVar3 = iVar3 + iVar1;
    }
    iVar2 = iVar2 + 1;
    puVar4 = puVar4 + 1;
  } while (iVar2 < 3);
  return iVar3;
}

