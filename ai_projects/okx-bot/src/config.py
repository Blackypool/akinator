# 📊 OKX SHORT BOT — ПАРАМЕТРЫ v8.2
# ====================================

# 🎯 ОСНОВНЫЕ ФИЛЬТРЫ
MIN_CORR = 0.20              # Корреляция < 0.20 (декоррелировано от BTC)
MIN_RR = 4.0                 # Минимальный Risk:Reward
MIN_FVG = 2                  # Минимум FVG для сигнала

# 💰 ОБЪЁМ 24H (ДОЛЛАРЫ)
MIN_24H_VOL_USD = 5_000_000  # $5M+ за сутки

# 📈 РИСК МЕНЕДЖМЕНТ
ATR_SL_MULT = 1.2            # SL = 1.2 × ATR
ATR_TP_MULT = 6.0            # TP = 6.0 × ATR (SHORT!)
RR_TARGET = 5.0              # R:R = TP/SL = 5:1

# 🔍 ТЕХНИЧЕСКИЕ ФИЛЬТРЫ
MANIP_WICK_RATIO = 3.0       # Wick/Body > 3.0 = манипуляция
MANIP_MAX_ANOMALIES = 5      # Макс аномалий за 3 дня (288 свечей)
FVG_LOOKBACK_CANDLES = 20    # FVG за 20 свечей (5 часов @ 15m)
TREND_LOOKBACK_CANDLES = 40  # Trend за 40 свечей (10 часов @ 15m)

# 📊 РАСПРЕДЕЛЕНИЕ СТРАТЕГИЙ (% от всех пар)
FVG_STRATEGY_PCT = 0.20      # 20% пар — только FVG
TREND_STRATEGY_PCT = 0.20    # 20% пар — только Trend
COMBO_STRATEGY_PCT = 0.60    # 60% пар — комбо строгий

# ⏰ ТЕХНИЧЕСКИЕ
SCAN_INTERVAL_SEC = 120           # Интервал сканов (секунды)
SLEEP_BETWEEN_SYMBOLS = 0.08      # Пауза между API запросами
CANDLE_TIMEFRAME = '15m'          # 15-минутный таймфрейм
MAX_SYMBOLS = 250                 # Максимум пар для анализа
API_TIMEOUT = 5                   # Таймаут API запросов

# 🔧 DEBUG РЕЖИМЫ
DEBUG_MODE = False                # Дополнительные логи
LOG_ALL_PAIRS = False             # Логировать все пары
SINGLE_SCAN_MODE = False          # Один скан и выход

print("✅ CONFIG v8.2 LOADED")
