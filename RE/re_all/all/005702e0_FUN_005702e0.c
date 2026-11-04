
uint FUN_005702e0(byte *param_1,byte *param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  
  pbVar5 = param_1;
  pbVar6 = param_1 + 1;
  bVar3 = *param_1;
  pbVar1 = param_1 + 2;
  pbVar2 = param_1 + 3;
  param_1 = (byte *)CONCAT13((byte)(&DAT_0084f458)[pbVar5[4]] >> 3 | (&DAT_0084f458)[*pbVar2] << 4,
                             CONCAT12((byte)(&DAT_0084f458)[*pbVar2] >> 4 |
                                      (&DAT_0084f458)[*pbVar1] * '\b',
                                      CONCAT11((byte)(&DAT_0084f458)[*pbVar1] >> 5 |
                                               (&DAT_0084f458)[*pbVar6] * '\x04',
                                               (&DAT_0084f458)[bVar3] * '\x02' |
                                               (byte)(&DAT_0084f458)[*pbVar6] >> 6)));
  pbVar5 = pbVar5 + 5;
  if (param_2 != (byte *)0x0) {
    uVar4 = (uint)param_1 / 7;
    uVar7 = (uint)param_1 % 7;
    if (uVar4 != 0) {
      pbVar6 = param_2;
      do {
        *pbVar6 = (&DAT_0084f458)[*pbVar5] * '\x02' | (byte)(&DAT_0084f458)[pbVar5[1]] >> 6;
        pbVar6[1] = (byte)(&DAT_0084f458)[pbVar5[2]] >> 5 | (&DAT_0084f458)[pbVar5[1]] * '\x04';
        pbVar6[2] = (byte)(&DAT_0084f458)[pbVar5[3]] >> 4 | (&DAT_0084f458)[pbVar5[2]] * '\b';
        pbVar6[3] = (byte)(&DAT_0084f458)[pbVar5[4]] >> 3 | (&DAT_0084f458)[pbVar5[3]] << 4;
        pbVar6[4] = (byte)(&DAT_0084f458)[pbVar5[5]] >> 2 | (&DAT_0084f458)[pbVar5[4]] << 5;
        pbVar6[5] = (byte)(&DAT_0084f458)[pbVar5[6]] >> 1 | (&DAT_0084f458)[pbVar5[5]] << 6;
        param_2 = pbVar6 + 7;
        pbVar6[6] = (&DAT_0084f458)[pbVar5[6]] << 7 | (&DAT_0084f458)[pbVar5[7]];
        pbVar5 = pbVar5 + 8;
        uVar4 = uVar4 - 1;
        pbVar6 = param_2;
      } while (uVar4 != 0);
    }
    if ((((uVar7 != 0) &&
         (*param_2 = (&DAT_0084f458)[*pbVar5] * '\x02' | (byte)(&DAT_0084f458)[pbVar5[1]] >> 6,
         1 < uVar7)) &&
        (param_2[1] = (byte)(&DAT_0084f458)[pbVar5[2]] >> 5 | (&DAT_0084f458)[pbVar5[1]] * '\x04',
        2 < uVar7)) &&
       (((param_2[2] = (byte)(&DAT_0084f458)[pbVar5[3]] >> 4 | (&DAT_0084f458)[pbVar5[2]] * '\b',
         3 < uVar7 &&
         (param_2[3] = (byte)(&DAT_0084f458)[pbVar5[4]] >> 3 | (&DAT_0084f458)[pbVar5[3]] << 4,
         4 < uVar7)) &&
        ((param_2[4] = (byte)(&DAT_0084f458)[pbVar5[5]] >> 2 | (&DAT_0084f458)[pbVar5[4]] << 5,
         5 < uVar7 &&
         (param_2[5] = (byte)(&DAT_0084f458)[pbVar5[6]] >> 1 | (&DAT_0084f458)[pbVar5[5]] << 6,
         6 < uVar7)))))) {
      param_2[6] = (&DAT_0084f458)[pbVar5[6]] << 7 | (&DAT_0084f458)[pbVar5[7]];
    }
  }
  return (uint)param_1;
}

