
void FUN_006bb970(undefined1 *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int *param_7,int *param_8)

{
  byte bVar1;
  byte *pbVar2;
  uint *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_30;
  undefined1 *local_2c;
  uint local_28;
  uint local_24 [9];
  
  local_30 = 0;
  do {
    local_2c = param_1;
    pbVar2 = (byte *)(local_30 + param_3);
    puVar3 = &local_28;
    iVar6 = 10;
    do {
      bVar1 = *pbVar2;
      pbVar2 = pbVar2 + param_4;
      *puVar3 = (uint)bVar1;
      puVar3 = puVar3 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    iVar8 = 0;
    iVar7 = 0;
    iVar6 = 4;
    puVar3 = &local_28;
    do {
      uVar5 = (int)(puVar3[1] - *puVar3) >> 0x1f;
      iVar7 = iVar7 + ((puVar3[1] - *puVar3 ^ uVar5) - uVar5);
      uVar5 = (int)(puVar3[5] - puVar3[6]) >> 0x1f;
      iVar8 = iVar8 + ((puVar3[5] - puVar3[6] ^ uVar5) - uVar5);
      iVar6 = iVar6 + -1;
      puVar3 = puVar3 + 1;
    } while (iVar6 != 0);
    *param_7 = *param_7 + (-(uint)(iVar7 < 0xff) & iVar7 - 0xffU) + 0xff;
    *param_8 = *param_8 + (-(uint)(iVar8 < 0xff) & iVar8 - 0xffU) + 0xff;
    if ((iVar7 < param_6) && (iVar8 < param_6)) {
      if ((param_5 <= (int)(local_24[4] - local_24[3])) ||
         (param_5 <= (int)(local_24[3] - local_24[4]))) goto LAB_006bbb33;
      local_2c = (undefined1 *)0x4;
      *param_1 = (char)((int)(local_28 * 3 + local_24[2] + 4 + local_24[0] * 2 + local_24[1] +
                             local_24[3]) >> 3);
      param_1[param_2] =
           (char)((int)(local_24[2] + 4 + (local_24[1] + local_28) * 2 + local_24[0] + local_24[3] +
                       local_24[4]) >> 3);
      puVar4 = param_1 + param_2 + param_2;
      puVar3 = local_24 + 3;
      do {
        *puVar4 = (char)((int)(puVar3[-4] + 4 + puVar3[-1] * 2 + puVar3[-3] + puVar3[-2] + puVar3[2]
                               + *puVar3 + puVar3[1]) >> 3);
        puVar4 = puVar4 + param_2;
        local_2c = (undefined1 *)((int)local_2c + -1);
        puVar3 = puVar3 + 1;
      } while (local_2c != (undefined1 *)0x0);
      *puVar4 = (char)((int)(local_24[7] + 4 + (local_24[6] + local_24[8]) * 2 + local_24[5] +
                             local_24[3] + local_24[4]) >> 3);
      puVar4[param_2] =
           (char)((int)(local_24[6] + local_24[8] * 3 + 4 + local_24[7] * 2 + local_24[5] +
                       local_24[4]) >> 3);
    }
    else {
LAB_006bbb33:
      puVar3 = local_24;
      iVar6 = 8;
      do {
        uVar5 = *puVar3;
        puVar3 = puVar3 + 1;
        *local_2c = (char)uVar5;
        local_2c = local_2c + param_2;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    param_1 = param_1 + 1;
    local_30 = local_30 + 1;
    if (7 < local_30) {
      return;
    }
  } while( true );
}

