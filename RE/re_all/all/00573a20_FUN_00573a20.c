
undefined4 FUN_00573a20(int *param_1,uint *param_2,int *param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  
  puVar1 = (undefined1 *)*param_1;
  if ((puVar1[1] & 0xfc) == 0xd8) {
    *param_2 = (((CONCAT11(puVar1[1],*puVar1) & 0x3ff) * 4 | (byte)puVar1[3] & 3) << 8 |
               (uint)(byte)puVar1[2]) + 0x10000;
    *param_1 = *param_1 + 4;
    *param_3 = *param_3 + 2;
    return 1;
  }
  uVar2 = (uint)CONCAT11(puVar1[1],*puVar1);
  *param_2 = uVar2;
  if (uVar2 == 0) {
    return 0;
  }
  *param_1 = *param_1 + 2;
  *param_3 = *param_3 + 1;
  return 1;
}

