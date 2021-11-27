<template>
  <v-main>
    <div class="filter-container">
      <v-text-field
        outlined
        type="date"
        v-model="selectedData"
      ></v-text-field>
      <v-btn @click="updateChartData">Gerar Gráfico</v-btn>
    </div>
    <v-checkbox
      v-model="unicEnter"
      label="Entrada Unica"
      class="checkbox"
    ></v-checkbox>
    
    <bar-chart :chartdata="chartData" v-if="loaded"/>
    
  </v-main>
</template>

<script>
import BarChart from './components/BarChart.vue'

export default {
  name: 'App',
  components: { BarChart },
  data() {
    return {
      chartData: {},
      loaded: false,
      selectedData: '',
      unicEnter: false
    }
  },
  methods: {
    getRandomInt() {
      return Math.floor(Math.random() * (50 - 5 + 1)) + 5;
    },
    updateChartData() {
      this.loaded = false;
      const selectedData = this.selectedData;
      const data = {};
      data.datasets = [];
      this.$http.get().then(resp => {
        const indicatorItens = resp.data.filter(row => `${row.date.charAt(3)}${row.date.charAt(4)}`  
          == `${selectedData.charAt(5)}${selectedData.charAt(6)}`);
        indicatorItens.forEach(dataItem => {
          const dataset = {};
          dataset.label = dataItem.date;
          dataset.backgroundColor = '#FC00FF';
          console.log('teste');
          dataset.data = [ this.unicEnter ? dataItem.count / 2 : dataItem.count ];
          data.datasets.push(dataset);
        });
        this.chartData = data;
        this.loaded = true;
      });
    }
  },
  mounted() {
    this.updateChartData();
  }
};
</script>

<style scoped>
  .filter-container {
    display: flex;
    margin: 20px;
    width: 500px;
  }
  
  .filter-container button {
    margin: 10px;
  }

  .checkbox {
    margin-left: 15px;
    margin-bottom: 10px;
  }

  .chartjs-render-monitor {
    background: linear-gradient(62deg, #8EC5FC 0%, #E0C3FC 100%);
}
</style>